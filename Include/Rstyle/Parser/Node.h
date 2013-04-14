// Node.h

#ifndef RSTYLE_PARSER_NODE_H
#define RSTYLE_PARSER_NODE_H

#include <string>
#include <memory>
#include <vector>
#include <stdexcept>



namespace rstyle
{


class Node
{
public :
	class Visitor;
	class ConstVisitor;
	typedef std::shared_ptr< Node > SharedPointer;

public :
	class IteratorImpl
	{
	public :
		typedef std::shared_ptr< IteratorImpl > SharedPointer;

		virtual bool operator !=( const IteratorImpl& other ) const noexcept = 0;
		virtual const Node::SharedPointer& operator *() const noexcept = 0;
		virtual IteratorImpl& operator ++() = 0;
	};

	class Iterator
	{
	public :
		typedef std::shared_ptr< Iterator > SharedPointer;

	public :
		Iterator( const IteratorImpl::SharedPointer& impl )
			: impl_{ impl }
		{
		}

		bool operator !=( const Iterator& other ) const
		{
			return (*impl_) != (*other.impl_);
		}

		Node& operator *()
		{
			return getValue();
		}

		const Node& operator *() const
		{
			return getValue();
		}

		Iterator operator ++()
		{
			++(*impl_);
			return *this;
		}

	private :
		Node& getValue() const
		{
			auto& node = **impl_;
			if (node == Node::null)
			{
				throw std::logic_error{ "Could not return iterator value in end position" };
			}
			return *node;
		}

	private :
		IteratorImpl::SharedPointer impl_;
	};

public :
	virtual ~Node() = default;

	virtual size_t getId() const = 0;
	virtual Node& getParent() const = 0;
	virtual std::string getName() const = 0;
	virtual std::string getValue() const = 0;
	virtual bool isComposite() const = 0;

	virtual void setValue( const std::string& value ) = 0;
	virtual void setId( size_t id ) = 0;
	virtual SharedPointer addNode( const std::string& name ) = 0;

	virtual void visit( Visitor& visitor ) = 0;
	virtual void visit( ConstVisitor& visitor ) const = 0;

	virtual Iterator begin() const = 0;
	virtual Iterator end() const = 0;

public :
	static const SharedPointer null;
};



class Node::Visitor
{
public :
	virtual ~Visitor() = default;

	virtual void accept( Node& node ) = 0;
};



class Node::ConstVisitor
{
public :
	virtual ~ConstVisitor() = default;

	virtual void accept( const Node& node ) = 0;
};


} // rstyle

#endif // RSTYLE_PARSER_NODE_H

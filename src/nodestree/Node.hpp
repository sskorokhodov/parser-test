// Node.hpp

#ifndef PARSER_NODESTREE_NODE_HPP
#define PARSER_NODESTREE_NODE_HPP

#include <string>
#include <memory>
#include <stdexcept>
#include <functional>

#include <nodestree/BaseNode.hpp>



namespace parser
{


template< class T >
class Node : public BaseNode
{
public :
	typedef T DataType;
	typedef std::shared_ptr< Node > SharedPointer;

	class Visitor;
	class ConstVisitor;
	class IteratorImpl;
	class Iterator;

	typedef std::function< void ( Node& ) > VisitorFunction;
	typedef std::function< void ( const Node& ) > ConstVisitorFunction;

public :
	virtual ~Node() noexcept = default;

	virtual void setData( const DataType& data ) = 0;
	virtual const DataType& getData() const = 0;

	virtual Node& getParent() const override = 0 ;

	virtual void visit( Visitor& visitor ) = 0;
	virtual void visit( ConstVisitor& visitor ) const = 0;

	virtual void visitWithFunction( const VisitorFunction& function ) = 0;
	virtual void visitWithFunctionConst( const ConstVisitorFunction& function ) const = 0;

	virtual Iterator begin() const = 0;
	virtual Iterator end() const = 0;

public :
	static const SharedPointer null;
};

template< class T >
const typename Node< T >::SharedPointer Node< T >::null;



template< class T >
class Node< T >::IteratorImpl
{
public :
	typedef std::shared_ptr< IteratorImpl > SharedPointer;

	virtual ~IteratorImpl() = default;

	virtual bool operator !=( const IteratorImpl& other ) const noexcept = 0;
	virtual const Node::SharedPointer& operator *() const noexcept = 0;
	virtual IteratorImpl& operator ++() = 0;
};



template< class T >
class Node< T >::Iterator final
{
public :
	typedef std::shared_ptr< Iterator > SharedPointer;

public :
	explicit Iterator( const typename IteratorImpl::SharedPointer& impl )
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
	typename IteratorImpl::SharedPointer impl_;
};



template< class T >
class Node< T >::Visitor
{
public :
	virtual ~Visitor() = default;

	virtual void accept( Node& node ) = 0;
};



template< class T >
class Node< T >::ConstVisitor
{
public :
	virtual ~ConstVisitor() = default;

	virtual void accept( const Node& node ) = 0;
};


} // parser

#endif // PARSER_NODESTREE_NODE_HPP

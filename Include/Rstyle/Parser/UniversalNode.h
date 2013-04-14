// UniversalNode.h

#ifndef RSTYLE_PARSER_UNIVERSAL_NODE_H
#define RSTYLE_PARSER_UNIVERSAL_NODE_H

#include <vector>

#include <Rstyle/Parser/Node.h>



namespace rstyle
{


class UniversalNode : public Node
{
private :
	typedef std::vector< Node::SharedPointer > NodesVector;

protected :
	class IteratorImpl : public Node::IteratorImpl
	{
	public :
		IteratorImpl( const NodesVector::const_iterator& subnodesIterator, const NodesVector* subnodes )
			: subnodesIterator_{ subnodesIterator }
			, subnodes_{ subnodes }
		{
		}

		virtual bool operator !=( const Node::IteratorImpl& other ) const noexcept override
		{
			if ( subnodesIterator_ ==  subnodes_->end() )
			{
				return Node::null != *other;
			}
			return *subnodesIterator_ != *other;
		}

		virtual const Node::SharedPointer& operator *() const noexcept override
		{
			if ( subnodesIterator_ ==  subnodes_->end() )
			{
				return Node::null;
			}
			return *subnodesIterator_;
		}

		virtual IteratorImpl& operator ++() override
		{
			++subnodesIterator_;
			return *this;
		}

	private :
		NodesVector::const_iterator subnodesIterator_;
		const NodesVector* subnodes_;
	};

public :
	UniversalNode(const std::string& name, Node* parent );
	UniversalNode( const UniversalNode& ) = delete;
	UniversalNode& operator =( const UniversalNode& ) = delete;
	virtual ~UniversalNode() noexcept = default;

	virtual size_t getId() const override;
	virtual std::string getName() const override;
	virtual bool isComposite() const override;
	virtual std::string getValue() const override;
	virtual Node& getParent() const override;

	virtual void setValue( const std::string& value ) override;
	virtual void setId( size_t id ) override;
	virtual SharedPointer addNode( const std::string& name ) override;
	virtual void visit( Visitor& visitor ) override;
	virtual void visit( ConstVisitor& visitor ) const override;

	virtual Iterator begin() const override
	{
		return Iterator{ std::make_shared< IteratorImpl >( subnodes_.begin(), &subnodes_ ) };
	}

	virtual Iterator end() const override
	{
		return Iterator{ std::make_shared< IteratorImpl >( subnodes_.end(), &subnodes_ ) };
	}

private :
	const std::string name_;
	Node* const parent_;
	std::string value_;
	NodesVector subnodes_;
	size_t id_;
};


} // rstyle

#endif // RSTYLE_PARSER_UNIVERSAL_NODE_H

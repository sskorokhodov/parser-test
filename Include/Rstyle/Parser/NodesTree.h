// NodesTree.h

#ifndef RSTYLE_PARSER_NODES_TREE_H
#define RSTYLE_PARSER_NODES_TREE_H

#include <Rstyle/Parser/Node.h>



namespace rstyle
{


class NodesTree : public Node
{
protected :
	class IteratorImpl : public Node::IteratorImpl
	{
	public :
		explicit IteratorImpl( const Node::SharedPointer& node )
			: node_{ node }
		{
		}

		virtual bool operator !=( const Node::IteratorImpl& other ) const noexcept override
		{
			return node_ != *other;
		}

		virtual const Node::SharedPointer& operator *() const noexcept override
		{
			return node_;
		}

		virtual IteratorImpl& operator ++() override
		{
			node_ = Node::null;
			return *this;
		}

	private :
		Node::SharedPointer node_;
	};

public :
	NodesTree();
	NodesTree( const NodesTree& ) = delete;
	NodesTree& operator =( const NodesTree& ) = delete;
	virtual ~NodesTree() noexcept = default;

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

	virtual Iterator begin() const override { return Iterator( std::make_shared< IteratorImpl >( firstNode_ ) ); }
	virtual Iterator end() const override { return Iterator( std::make_shared< IteratorImpl >( Node::null ) ); }

	size_t countSubnodes() const;

private :
	size_t id_;
	Node::SharedPointer firstNode_;
};


} // rstyle

#endif // RSTYLE_PARSER_NODES_TREE_H

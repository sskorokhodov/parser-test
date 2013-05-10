// NodesTree.hpp

#ifndef RSTYLE_NODESTREE_NODES_TREE_HPP
#define RSTYLE_NODESTREE_NODES_TREE_HPP

#include <rstyle/nodestree/Node.hpp>
#include <rstyle/nodestree/UniversalNode.hpp>

#include <stdexcept>



namespace rstyle
{


template< class T >
class NodesTree : public Node< T >
{
protected :

	class IteratorImpl;



public :

	NodesTree()
		: firstNode_{}
		, data_{}
	{
	}



	NodesTree( const NodesTree& ) = delete;
	NodesTree& operator =( const NodesTree& ) = delete;
	virtual ~NodesTree() noexcept = default;



	virtual void setData( const typename Node< T >::DataType& data ) override
	{
		data_ = data;
	}



	virtual const typename Node< T >::DataType& getData() const override
	{
		return data_;
	}


	virtual std::string getName() const override
	{
		throw std::logic_error{ "Nodes tree has no name" };
	}



	virtual bool isComposite() const override
	{
		return true;
	}



	virtual std::string getValue() const override
	{
		throw std::logic_error{ "Nodes tree has no value" };
	}



	virtual void setValue( const std::string& ) override
	{
		throw std::logic_error{ "Could not add value to nodes tree" };
	}



	virtual Node< T >& addNode( const std::string& name ) override
	{
		firstNode_ = std::make_shared< UniversalNode< T > >( name, this );
		return *firstNode_;
	}



	virtual Node< T >& getParent() const override
	{
		throw std::logic_error{ "Nodes tree has no parent" };
	}



	virtual void visit( typename Node< T >::Visitor& visitor ) override
	{
		firstNode_->visit( visitor );
	}



	virtual void visit( typename Node< T >::ConstVisitor& visitor ) const override
	{
		firstNode_->visit( visitor );
	}



	virtual void visitWithFunction( const typename Node< T >::VisitorFunction& function ) override
	{
		firstNode_->visitWithFunction( function );
	}



	virtual void visitWithFunctionConst( const typename Node< T >::ConstVisitorFunction& function ) const override
	{
		firstNode_->visitWithFunctionConst( function );
	}



	virtual typename Node< T >::Iterator begin() const override
	{
		return typename Node< T >::Iterator{ std::make_shared< IteratorImpl >( firstNode_ ) };
	}



	virtual typename Node< T >::Iterator end() const override
	{
		return typename Node< T >::Iterator{ std::make_shared< IteratorImpl >( Node< T >::null ) };
	}



	size_t countSubnodes() const
	{
		size_t count = 0;
		firstNode_->visitWithFunctionConst( [&count]( const Node< T >& ){ ++count; } );
		return count;
	}



private :

	typename Node< T >::SharedPointer firstNode_;
	typename Node< T >::DataType data_;
};





template< class T >
class NodesTree< T >::IteratorImpl : public Node< T >::IteratorImpl
{
public :
	explicit IteratorImpl( const typename Node< T >::SharedPointer& node )
		: node_{ node }
	{
	}

	virtual bool operator !=( const typename Node< T >::IteratorImpl& other ) const noexcept override
	{
		return node_ != *other;
	}

	virtual const typename Node< T >::SharedPointer& operator *() const noexcept override
	{
		return node_;
	}

	virtual IteratorImpl& operator ++() override
	{
		node_ = Node< T >::null;
		return *this;
	}

private :
	typename Node< T >::SharedPointer node_;
};


} // rstyle

#endif // RSTYLE_NODESTREE_NODES_TREE_HPP

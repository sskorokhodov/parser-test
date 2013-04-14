// NodesTree.h

#include <Rstyle/Parser/NodesTree.h>
#include <Rstyle/Parser/UniversalNode.h>

#include <stdexcept>



namespace rstyle
{


namespace
{
	class CountNodesVisitor : public rstyle::Node::Visitor
	{
	public :
		CountNodesVisitor()
			: count_{ 0 }
		{
		}

		virtual void accept( rstyle::Node& ) override
		{
			++count_;
		}

		size_t getCount() const
		{
			return count_;
		}

	private :
		size_t count_;
	};
} //



NodesTree::NodesTree()
	: id_{ 0 }
	, firstNode_{ 0 }
{
}



size_t
NodesTree::getId() const
{
	return id_;
}



std::string
NodesTree::getName() const
{
	throw std::logic_error{ "Nodes tree has no name" };
}



bool
NodesTree::isComposite() const
{
	return true;
}



std::string
NodesTree::getValue() const
{
	throw std::logic_error{ "Nodes tree has no value" };
}



void
NodesTree::setValue( const std::string& )
{
	throw std::logic_error{ "Could not add value to nodes tree" };
}



void
NodesTree::setId( size_t id )
{
	id_ = id;
}



Node::SharedPointer
NodesTree::addNode( const std::string& name )
{
	firstNode_ = std::make_shared< UniversalNode >( name, this );
	return firstNode_;
}



Node&
NodesTree::getParent() const
{
	throw std::logic_error{ "Nodes tree has no parent" };
}



void
NodesTree::visit( Visitor& visitor )
{
	firstNode_->visit( visitor );
}



void
NodesTree::visit( ConstVisitor& visitor ) const
{
	firstNode_->visit( visitor );
}



size_t
NodesTree::countSubnodes() const
{
	CountNodesVisitor counter;
	firstNode_->visit( counter );
	return counter.getCount();
}


} // rstyle

// UniversalNode.cpp

#include <Rstyle/Parser/UniversalNode.h>
#include <stdexcept>



namespace rstyle
{


UniversalNode::UniversalNode( const std::string name, Node* parent ) :
	id_( 0 ),
	name_( name ),
	parent_( parent )
{
}



UniversalNode::~UniversalNode() 
{
	for ( auto node : subnodes_ )
	{
		delete node;
	}
}



size_t 
UniversalNode::getId() const
{
	return id_;
}



std::string 
UniversalNode::getName() const
{
	return name_;
}



bool 
UniversalNode::isComposite() const
{
	return !subnodes_.empty();
}



std::string 
UniversalNode::getValue() const
{
	return value_;
}



void 
UniversalNode::setValue( const std::string& value )
{
	if ( !subnodes_.empty() )
	{
		throw std::logic_error( "Could not add value to composite node" );
	}
	value_ = value;
}



void 
UniversalNode::setId( size_t id )
{
	id_ = id;
}



Node* 
UniversalNode::addNode( const std::string& name )
{
	value_.clear();
	Node* subnode = new UniversalNode( name, this );
	subnodes_.push_back( subnode );
	return subnode;
}



Node* 
UniversalNode::getParent() const
{
	return parent_;
}



void 
UniversalNode::visit( Visitor& visitor )
{
	visitor.accept( *this );
	for ( NodesIterator iNode = subnodes_.begin(); iNode != subnodes_.end(); ++iNode )
	{
		(*iNode)->visit( visitor );
	}
}



void 
UniversalNode::visit( ConstVisitor& visitor ) const
{
	visitor.accept( *this );
	for ( NodesConstIterator iNode = subnodes_.begin(); iNode != subnodes_.end(); ++iNode )
	{
		(*iNode)->visit( visitor );
	}
}


} // rstyle

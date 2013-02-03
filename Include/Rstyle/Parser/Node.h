// Node.h

#ifndef RSTYLE_PARSER_NODE_H
#define RSTYLE_PARSER_NODE_H

#include <string>



namespace rstyle
{


class Node
{
public :
	class Visitor;
	class ConstVisitor;

public :
	virtual ~Node() {}

	virtual size_t getId() const = 0;
	virtual Node* getParent() const = 0;
	virtual std::string getName() const = 0;
	virtual std::string getValue() const = 0;
	virtual bool isComposite() const = 0;

	virtual void setValue( const std::string& value ) = 0;
	virtual void setId( size_t id ) = 0;
	virtual Node* addNode( const std::string& name ) = 0;

	virtual void visit( Visitor& visitor ) = 0;
	virtual void visit( ConstVisitor& visitor ) const = 0;
};



class Node::Visitor
{
public :
	virtual ~Visitor() {}

	virtual void accept( Node& node ) = 0;
};



class Node::ConstVisitor
{
public :
	virtual ~ConstVisitor() {}

	virtual void accept( const Node& node ) = 0;
};


} // rstyle

#endif // RSTYLE_PARSER_NODE_H

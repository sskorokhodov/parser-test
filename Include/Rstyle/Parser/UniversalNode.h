// UniversalNode.h

#ifndef RSTYLE_PARSER_UNIVERSAL_NODE_H
#define RSTYLE_PARSER_UNIVERSAL_NODE_H

#include <vector>

#include <Rstyle/Parser/Node.h>



namespace rstyle
{


class UniversalNode : public Node
{
public :
	UniversalNode( const std::string name, Node* parent );
	virtual ~UniversalNode();

	virtual size_t getId() const;
	virtual std::string getName() const;
	virtual bool isComposite() const;
	virtual std::string getValue() const;
	virtual Node* getParent() const;

	virtual void setValue( const std::string& value );
	virtual void setId( size_t id );
	virtual Node* addNode( const std::string& name );
	virtual void visit( Visitor& visitor );
	virtual void visit( ConstVisitor& visitor ) const;

private :
	UniversalNode( const UniversalNode& );
	UniversalNode& operator =( const UniversalNode& );

private :
	typedef std::vector< Node* > NodesVector;
	typedef NodesVector::iterator NodesIterator;
	typedef NodesVector::const_iterator NodesConstIterator;

	NodesVector subnodes_;
	size_t id_;
	std::string name_;
	Node* parent_;
	std::string value_;
};


} // rstyle

#endif // RSTYLE_PARSER_UNIVERSAL_NODE_H

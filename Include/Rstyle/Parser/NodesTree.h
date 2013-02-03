// NodesTree.h

#ifndef RSTYLE_PARSER_NODES_TREE_H
#define RSTYLE_PARSER_NODES_TREE_H

#include <Rstyle/Parser/Node.h>



namespace rstyle
{


class NodesTree : public Node
{
public :
	NodesTree();
	virtual ~NodesTree(); 

	virtual size_t getId() const;
	virtual std::string getName() const;
	virtual bool isComposite() const;
	virtual std::string getValue() const;
	virtual Node* getParent() const;

	size_t count() const;

	virtual void setValue( const std::string& value );
	virtual void setId( size_t id );
	virtual Node* addNode( const std::string& name );
	virtual void visit( Visitor& visitor );
	virtual void visit( ConstVisitor& visitor ) const;

private :
	NodesTree( const NodesTree& );
	NodesTree& operator =( const NodesTree& );

private :
    size_t id_;
    Node* firstNode_;
};


} // rstyle

#endif // RSTYLE_PARSER_NODES_TREE_H

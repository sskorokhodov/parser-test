#ifndef RSTYLE_NODESTREE_BASE_NODE_HPP
#define RSTYLE_NODESTREE_BASE_NODE_HPP

#include <string>



namespace rstyle
{


class BaseNode
{
public :
	virtual ~BaseNode() = default;

	virtual BaseNode& getParent() const = 0;
	virtual std::string getName() const = 0;
	virtual std::string getValue() const = 0;
	virtual bool isComposite() const = 0;

	virtual void setValue( const std::string& value ) = 0;
	virtual BaseNode& addNode( const std::string& name ) = 0;
};


} // rstyle

#endif // RSTYLE_NODESTREE_BASE_NODE_HPP

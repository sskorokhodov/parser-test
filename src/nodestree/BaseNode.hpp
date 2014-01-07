// BaseNode.hpp

#ifndef PARSER_NODESTREE_BASE_NODE_HPP
#define PARSER_NODESTREE_BASE_NODE_HPP

#include <string>



namespace parser
{


/**
 * @brief The BaseNode class is intend to supply *minimal non-template node interface*.
 *
 * Usually to work with that class is the best choice when you need only to add nodes to tree or
 * use simple node attributes like name or string value.
 *
 * When you need to walk through nodes tree, or keep/process nodes data, you have to look for more
 * complicated derived class.
 */
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


} // parser

#endif // PARSER_NODESTREE_BASE_NODE_HPP

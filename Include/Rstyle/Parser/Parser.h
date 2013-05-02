// Parser.h

#ifndef RSTYLE_PARSER_PARSER_H
#define RSTYLE_PARSER_PARSER_H

#include <string>

#include <rstyle/nodestree/Node.hpp>



namespace rstyle
{


class Parser
{
public :
	Parser() = default;
	Parser( const Parser& ) = default;
	Parser& operator =( const Parser& ) = default;
	virtual ~Parser() = default;

	virtual void parse( const std::string& document, BaseNode& node ) const;
};


} // rstyle

#endif // RSTYLE_PARSER_PARSER_H

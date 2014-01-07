// Parser.h

#ifndef PARSER_PARSER_PARSER_H
#define PARSER_PARSER_PARSER_H

#include <string>

#include <nodestree/Node.hpp>



namespace parser
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


} // parser

#endif // PARSER_PARSER_PARSER_H

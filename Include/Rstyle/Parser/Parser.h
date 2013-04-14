// Parser.h

#ifndef RSTYLE_PARSER_PARSER_H
#define RSTYLE_PARSER_PARSER_H

#include <string>

#include <Rstyle/Parser/Node.h>



namespace rstyle
{


class Parser
{
public :
	Parser() = default;
	Parser( const Parser& ) = default;
	Parser& operator =( const Parser& ) = default;
	virtual ~Parser() = default;

	virtual Node::SharedPointer parse( const std::string& document ) const;
};


} // rstyle

#endif // RSTYLE_PARSER_PARSER_H

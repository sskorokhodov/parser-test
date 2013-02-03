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
	typedef std::string::const_iterator StringConstIterator;

public :
	Parser();
	Parser( const Parser& );
	virtual ~Parser();

	Parser& operator =( const Parser& );

	void parse( Node& root, const std::string& document ) const;
};


} // rstyle

#endif // RSTYLE_PARSER_PARSER_H

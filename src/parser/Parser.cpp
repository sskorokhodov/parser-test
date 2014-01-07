// Parser.h

#include <parser/Parser.h>

#include <parser/LexemesList.h>



namespace parser
{


void Parser::parse( const std::string& document, BaseNode& node ) const
{
	LexemesList lexemes{ document };
	lexemes.fillTree( node );
}


} // parser

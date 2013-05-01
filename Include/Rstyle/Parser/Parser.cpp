// Parser.h

#include <rstyle/parser/Parser.h>

#include <rstyle/parser/LexemesList.h>



namespace rstyle
{


void Parser::parse( const std::string& document, BaseNode& node ) const
{
	LexemesList lexemes{ document };
	lexemes.fillTree( node );
}


} // rstyle

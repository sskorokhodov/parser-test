// Parser.h

#include <rstyle/parser/Parser.h>

#include <rstyle/parser/LexemesList.h>



namespace rstyle
{


Node< int >::SharedPointer Parser::parse(const std::string& document ) const
{
	LexemesList lexemes{ document };
	return lexemes.fillTree();
}


} // rstyle

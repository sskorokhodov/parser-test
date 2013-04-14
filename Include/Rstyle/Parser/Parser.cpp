// Parser.h

#include <Rstyle/Parser/Parser.h>

#include <Rstyle/Parser/LexemesList.h>



namespace rstyle
{


Node< int >::SharedPointer Parser::parse(const std::string& document ) const
{
	LexemesList lexemes{ document };
	return lexemes.fillTree();
}


} // rstyle

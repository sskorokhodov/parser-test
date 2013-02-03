// Parser.h

#include <Rstyle/Parser/Parser.h>

#include <Rstyle/Parser/LexemesList.h>



namespace rstyle
{


Parser::Parser()
{
}


	
Parser::Parser( const Parser& )
{
}



Parser::~Parser()
{
}



Parser& 
Parser::operator =( const Parser& )
{
	return *this;
}



void 
Parser::parse( Node& root, const std::string& document ) const
{
	LexemesList lexemes;
	lexemes.read( document );
	lexemes.fillNode( root );
}


} // rstyle

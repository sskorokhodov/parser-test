// LexemesList.cpp

#include <Rstyle/Parser/LexemesList.h>

#include <Rstyle/Parser/NameLexeme.h>
#include <Rstyle/Parser/LexemesPairsMatchChecker.h>



namespace rstyle
{


LexemesList::LexemesList()
{
}



void
LexemesList::read( const std::string& document )
{
	static const size_t nSymbolsPerLexemeExpected = 3;
	size_t nLexemesToReserve = document.size() / nSymbolsPerLexemeExpected;
	lexemes_.reserve( nLexemesToReserve );
	LexemesPairsMatchChecker matchChecker;

	for ( 
        Lexeme* lexeme = new NameLexeme( document.begin(), document );
		lexeme != 0; 
		lexeme = lexeme->parseNext( document )
	)
	{
		lexemes_.push_back( lexeme );
		matchChecker.check( *lexeme );
	}
	matchChecker.checkFinal();
}



LexemesList::~LexemesList()
{
    for ( auto lexeme : lexemes_ )
	{
		delete lexeme;
	}
}



void 
LexemesList::fillNode( Node& node )
{
	Node* nextNode = &node;
    for ( auto lexeme : lexemes_ )
	{
        nextNode = lexeme->applyTo( nextNode );
	}
}


} // rstyle

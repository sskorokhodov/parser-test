// LexemesList.cpp

#include <rstyle/parser/LexemesList.h>

#include <rstyle/parser/LexemesPairsMatchChecker.h>
#include <rstyle/parser/NameLexeme.h>
#include <rstyle/nodestree/NodesTree.hpp>


namespace rstyle
{


LexemesList::LexemesList( const std::string& document )
	: lexemes_{ read( document ) }
{
}



LexemesList::LexemesVector
LexemesList::read( const std::string& document )
{
	LexemesVector lexemes;
	static const size_t nSymbolsPerLexemeExpected = 3;
	size_t nLexemesToReserve = document.size() / nSymbolsPerLexemeExpected;
	lexemes.reserve( nLexemesToReserve );
	LexemesPairsMatchChecker matchChecker;

	for (
		Lexeme::SharedPointer lexeme = std::make_shared< NameLexeme >( document.begin(), document );
		lexeme != Lexeme::null;
		lexeme = lexeme->parseNext( document )
	)
	{
		lexemes.push_back( lexeme );
		matchChecker.check( *lexeme );
	}
	matchChecker.checkFinal();
	return lexemes;
}



void
LexemesList::fillTree( BaseNode& root ) const
{
	BaseNode* nextNode = &root;
	for ( const auto& lexeme : lexemes_ )
	{
		nextNode = &(lexeme->applyTo( *nextNode ));
	}
}


} // rstyle

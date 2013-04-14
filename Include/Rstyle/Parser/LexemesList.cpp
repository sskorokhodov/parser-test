// LexemesList.cpp

#include <Rstyle/Parser/LexemesList.h>

#include <Rstyle/Parser/LexemesPairsMatchChecker.h>
#include <Rstyle/Parser/NameLexeme.h>
#include <Rstyle/Parser/NodesTree.h>


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



Node::SharedPointer
LexemesList::fillTree() const
{
	auto root = std::make_shared< NodesTree >();
	Node* nextNode = root.get();
	for ( const auto& lexeme : lexemes_ )
	{
		nextNode = &(lexeme->applyTo( *nextNode ));
	}
	return root;
}


} // rstyle

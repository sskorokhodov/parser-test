// LexemesPairsMatchChecker.cpp

#include <Rstyle/Parser/LexemesPairsMatchChecker.h>

#include <Rstyle/Parser/Exceptions.h>



namespace rstyle
{


LexemesPairsMatchChecker::LexemesPairsMatchChecker()
{
}


	
LexemesPairsMatchChecker::LexemesPairsMatchChecker( const LexemesPairsMatchChecker& checker ) :
	matches_( checker.matches_ )
{
}



LexemesPairsMatchChecker::~LexemesPairsMatchChecker()
{
}



LexemesPairsMatchChecker&
LexemesPairsMatchChecker::operator =( const LexemesPairsMatchChecker& checker )
{
	matches_ = checker.matches_ ;
	return *this;
}



void 
LexemesPairsMatchChecker::check( const Lexeme& lexeme )
{
	int& count = matches_[ lexeme.getType() ];
	lexeme.changeExpectedMatches( count );
	if ( count < 0 )
	{
		throw SyntaxException( "Unexpected pair closing lexeme" );
	}
}



void 
LexemesPairsMatchChecker::checkFinal() const
{
	for ( MatchesConstIterator iMatch = matches_.begin(); iMatch != matches_.end(); ++iMatch )
	{
		if ( iMatch->second != 0 )
		{
			throw SyntaxException( "There is no some pair closing lexemes" );
		}
	}
}


} // rstyle

// LexemesPairsMatchChecker.cpp

#include <parser/Exceptions.h>
#include <parser/utils/LexemesPairsMatchChecker.h>



namespace parser
{


LexemesPairsMatchChecker::LexemesPairsMatchChecker( const LexemesPairsMatchChecker& checker )
	: matches_{ checker.matches_ }
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
	count = lexeme.changeExpectedMatches( count );
	if ( count < 0 )
	{
		throw SyntaxException{ "Unexpected pair closing lexeme" };
	}
}



void
LexemesPairsMatchChecker::checkFinal() const
{
	for ( auto match : matches_ )
	{
		if ( match.second != 0 )
		{
			throw SyntaxException{ "There is no some pair closing lexemes" };
		}
	}
}


} // parser

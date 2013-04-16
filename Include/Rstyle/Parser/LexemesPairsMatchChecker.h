// LexemesPairsMatchChecker.h

#include <map>

#include <rstyle/parser/Lexeme.h>



namespace rstyle
{


class LexemesPairsMatchChecker
{
public :
	LexemesPairsMatchChecker() = default;
	LexemesPairsMatchChecker( const LexemesPairsMatchChecker& checker );
	LexemesPairsMatchChecker& operator =( const LexemesPairsMatchChecker& checker );
	virtual ~LexemesPairsMatchChecker() = default;

	void checkFinal() const;
	void check( const Lexeme& lexeme );

private :
	typedef std::map< LexemeType, int > MatchesMap;
	typedef MatchesMap::const_iterator MatchesConstIterator;
	MatchesMap matches_;
};


} // rstyle

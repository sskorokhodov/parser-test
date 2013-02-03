// LexemesPairsMatchChecker.h

#include <map>

#include <Rstyle/Parser/Lexeme.h>



namespace rstyle
{


class LexemesPairsMatchChecker
{
public :
	LexemesPairsMatchChecker();
	LexemesPairsMatchChecker( const LexemesPairsMatchChecker& checker );
	virtual ~LexemesPairsMatchChecker();

	LexemesPairsMatchChecker& operator =( const LexemesPairsMatchChecker& checker );

	void checkFinal() const;
	void check( const Lexeme& lexeme );

private :
	typedef std::map< LexemeType::Type, int > MatchesMap;
	typedef MatchesMap::const_iterator MatchesConstIterator;
	MatchesMap matches_;
};


} // rstyle

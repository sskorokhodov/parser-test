// Utils.h

#ifndef RSTYLE_PARSER_UTILS_H
#define RSTYLE_PARSER_UTILS_H

#include <string>



namespace rstyle
{


typedef std::string::const_iterator StringConstIterator;

StringConstIterator
skipSpaces( StringConstIterator iStart, const std::string& document );



class LexemePattern
{
public :
	explicit LexemePattern( char symbol );
	LexemePattern( char first, char last );
	LexemePattern( const LexemePattern& pattern );
	virtual ~LexemePattern();

	bool isMatch( char symbol ) const;

private :
	LexemePattern& operator =( const LexemePattern& pattern );

private :
	const char first_;
	const char last_;
};


} // rstyle

#endif // RSTYLE_PARSER_UTILS_H

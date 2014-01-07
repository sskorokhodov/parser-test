// Utils.h

#ifndef PARSER_PARSER_UTILS_H
#define PARSER_PARSER_UTILS_H

#include <string>



namespace parser
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
	LexemePattern& operator =( const LexemePattern& pattern ) = delete;
	virtual ~LexemePattern() = default;

	bool isMatch( char symbol ) const;

private :
	const char first_;
	const char last_;
};


} // parser

#endif // PARSER_PARSER_UTILS_H

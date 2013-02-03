// Lexeme.h

#ifndef RSTYLE_PARSER_LEXEME_H
#define RSTYLE_PARSER_LEXEME_H

#include <Rstyle/Parser/Node.h>



namespace rstyle
{


class LexemeType
{
public :
	enum Type
	{
		NAME,
		LIST,
		ASSIGN,
		VALUE
	};
};



class Lexeme
{
public :
	virtual ~Lexeme() {}

	virtual Node* applyTo( Node* node ) const = 0;
	virtual LexemeType::Type getType() const = 0;
	virtual void changeExpectedMatches( int& count ) const = 0;

	virtual Lexeme* parseNext( const std::string& document ) = 0;
};


} // rstyle

#endif // RSTYLE_PARSER_LEXEME_H

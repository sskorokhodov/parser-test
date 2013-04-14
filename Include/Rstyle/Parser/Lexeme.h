// Lexeme.h

#ifndef RSTYLE_PARSER_LEXEME_H
#define RSTYLE_PARSER_LEXEME_H

#include <Rstyle/Parser/Node.h>
#include <memory>



namespace rstyle
{


enum class LexemeType
{
	NAME,
	LIST,
	ASSIGN,
	VALUE
};



class Lexeme
{
public :
	typedef std::shared_ptr< Lexeme > SharedPointer;

public :
	virtual ~Lexeme() = default;

	virtual SharedPointer parseNext( const std::string& document ) const = 0;
	virtual Node& applyTo( Node& node ) const = 0;
	virtual LexemeType getType() const = 0;
	virtual void changeExpectedMatches( int& count ) const = 0;

	static const SharedPointer null;
};


} // rstyle

#endif // RSTYLE_PARSER_LEXEME_H

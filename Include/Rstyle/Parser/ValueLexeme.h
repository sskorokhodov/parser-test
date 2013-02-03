// ValueLexeme.h

#ifndef RSTYLE_PARSER_VALUE_LEXEME_H
#define RSTYLE_PARSER_VALUE_LEXEME_H

#include <Rstyle/Parser/Lexeme.h>
#include <Rstyle/Parser/Utils.h>



namespace rstyle
{


class ValueLexeme : public Lexeme
{
public :
	ValueLexeme( const StringConstIterator& iStart, const std::string& document );
	virtual ~ValueLexeme();
	
	virtual Node* applyTo( Node* node ) const;
	virtual LexemeType::Type getType() const;
	virtual void changeExpectedMatches( int& count ) const;

	virtual Lexeme* parseNext( const std::string& document );

private :
	ValueLexeme( const ValueLexeme& );
	ValueLexeme& operator =( const ValueLexeme& );
	
private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_VALUE_LEXEME_H

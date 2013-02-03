// NameLexeme.h

#ifndef RSTYLE_PARSER_NAME_LEXEME_H
#define RSTYLE_PARSER_NAME_LEXEME_H

#include <Rstyle/Parser/Lexeme.h>
#include <Rstyle/Parser/Utils.h>



namespace rstyle
{


class NameLexeme : public Lexeme
{
public :
	NameLexeme( const StringConstIterator& iStart, const std::string& document );
	virtual ~NameLexeme();

	virtual Node* applyTo( Node* node ) const;
	virtual LexemeType::Type getType() const;
	virtual void changeExpectedMatches( int& count ) const;

	virtual Lexeme* parseNext( const std::string& document );

private :
	NameLexeme( const NameLexeme& );
	NameLexeme& operator =( const NameLexeme& );
	
private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_NAME_LEXEME_H

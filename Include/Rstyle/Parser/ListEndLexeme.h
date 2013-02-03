// ListEndLexeme.h

#ifndef RSTYLE_PARSER_LIST_END_LEXEME_H
#define RSTYLE_PARSER_LIST_END_LEXEME_H

#include <Rstyle/Parser/Lexeme.h>
#include <Rstyle/Parser/Utils.h>



namespace rstyle
{


class ListEndLexeme : public Lexeme
{
public :
	ListEndLexeme( const StringConstIterator& iStart, const std::string& document );
	virtual ~ListEndLexeme();

	virtual Node* applyTo( Node* node ) const;
	virtual LexemeType::Type getType() const;
	virtual void changeExpectedMatches( int& count ) const;

	virtual Lexeme* parseNext( const std::string& document );

private :
	ListEndLexeme( const ListEndLexeme& );
	ListEndLexeme& operator =( const ListEndLexeme& );

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_LIST_END_LEXEME_H

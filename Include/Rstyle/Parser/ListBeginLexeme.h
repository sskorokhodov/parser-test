// ListBeginLexeme.h

#ifndef RSTYLE_PARSER_LIST_BEGIN_LEXEME_H
#define RSTYLE_PARSER_LIST_BEGIN_LEXEME_H

#include <Rstyle/Parser/Lexeme.h>
#include <Rstyle/Parser/Utils.h>



namespace rstyle
{


class ListBeginLexeme : public Lexeme
{
public :
	ListBeginLexeme( const StringConstIterator& iStart, const std::string& document );
	virtual ~ListBeginLexeme();

	virtual Node* applyTo( Node* node ) const;
	virtual LexemeType::Type getType() const;
	virtual void changeExpectedMatches( int& count ) const;

	virtual Lexeme* parseNext( const std::string& document );

private :
	ListBeginLexeme( const ListBeginLexeme& );
	ListBeginLexeme& operator =( const ListBeginLexeme& );

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_LIST_BEGIN_LEXEME_H

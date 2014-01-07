// ListEndLexeme.h

#ifndef PARSER_PARSER_LIST_END_LEXEME_H
#define PARSER_PARSER_LIST_END_LEXEME_H

#include <parser/lexemes/Lexeme.h>
#include <parser/utils/Utils.h>



namespace parser
{


class ListEndLexeme : public Lexeme
{
public :
	ListEndLexeme( const StringConstIterator& iStart, const std::string& document );
	ListEndLexeme( const ListEndLexeme& ) = delete;
	ListEndLexeme& operator =( const ListEndLexeme& ) = delete;
	virtual ~ListEndLexeme() noexcept = default;

	virtual BaseNode& applyTo( BaseNode& node ) const override;
	virtual LexemeType getType() const override;
	virtual int changeExpectedMatches( int count ) const override;
	virtual SharedPointer parseNext( const std::string& document ) const override;

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // parser

#endif // PARSER_PARSER_LIST_END_LEXEME_H

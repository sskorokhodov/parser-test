// NameLexeme.h

#ifndef PARSER_PARSER_NAME_LEXEME_H
#define PARSER_PARSER_NAME_LEXEME_H

#include <parser/lexemes/Lexeme.h>
#include <parser/utils/Utils.h>



namespace parser
{


class NameLexeme : public Lexeme
{
public :
	NameLexeme( const StringConstIterator& iStart, const std::string& document );
	NameLexeme( const NameLexeme& ) = delete;
	NameLexeme& operator =( const NameLexeme& ) = delete;
	virtual ~NameLexeme() noexcept = default;

	virtual BaseNode& applyTo( BaseNode& node ) const override;
	virtual LexemeType getType() const override;
	virtual int changeExpectedMatches( int count ) const override;
	virtual SharedPointer parseNext( const std::string& document ) const override;

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // parser

#endif // PARSER_PARSER_NAME_LEXEME_H

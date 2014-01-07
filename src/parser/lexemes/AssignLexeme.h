// AssignLexeme.h

#ifndef PARSER_PARSER_ASSIGN_LEXEME_H
#define PARSER_PARSER_ASSIGN_LEXEME_H

#include <parser/lexemes/Lexeme.h>
#include <parser/utils/Utils.h>



namespace parser
{


class AssignLexeme : public Lexeme
{
public :
	AssignLexeme( const StringConstIterator& iStart, const std::string& document );
	AssignLexeme( const AssignLexeme& ) = delete;
	AssignLexeme& operator =( const AssignLexeme& ) = delete;
	virtual ~AssignLexeme() noexcept = default;

	virtual BaseNode& applyTo( BaseNode& node ) const override;
	virtual LexemeType getType() const override;
	virtual int changeExpectedMatches( int count ) const override;
	virtual Lexeme::SharedPointer parseNext( const std::string& document ) const override;

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // parser

#endif // PARSER_PARSER_ASSIGN_LEXEME_H

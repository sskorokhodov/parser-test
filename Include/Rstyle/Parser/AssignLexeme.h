// AssignLexeme.h

#ifndef RSTYLE_PARSER_ASSIGN_LEXEME_H
#define RSTYLE_PARSER_ASSIGN_LEXEME_H

#include <rstyle/parser/Lexeme.h>
#include <rstyle/parser/Utils.h>



namespace rstyle
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
	virtual void changeExpectedMatches( int& count ) const override;
	virtual Lexeme::SharedPointer parseNext( const std::string& document ) const override;

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_ASSIGN_LEXEME_H

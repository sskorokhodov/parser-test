// AssignLexeme.h

#ifndef RSTYLE_PARSER_ASSIGN_LEXEME_H
#define RSTYLE_PARSER_ASSIGN_LEXEME_H

#include <Rstyle/Parser/Lexeme.h>
#include <Rstyle/Parser/Utils.h>



namespace rstyle
{


class AssignLexeme : public Lexeme
{
public :
	AssignLexeme( const StringConstIterator& iStart, const std::string& document );
	AssignLexeme( const AssignLexeme& ) = delete;
	AssignLexeme& operator =( const AssignLexeme& ) = delete;
	virtual ~AssignLexeme() noexcept = default;

	virtual Node& applyTo( Node& node ) const override;
	virtual LexemeType getType() const override;
	virtual void changeExpectedMatches( int& count ) const override;
	virtual Lexeme::SharedPointer parseNext( const std::string& document ) const override;

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_ASSIGN_LEXEME_H

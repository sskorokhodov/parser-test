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
	ValueLexeme( const ValueLexeme& ) = delete;
	ValueLexeme& operator =( const ValueLexeme& ) = delete;
	virtual ~ValueLexeme() noexcept = default;

	virtual Node& applyTo(Node& node ) const override;
	virtual LexemeType getType() const override;
	virtual void changeExpectedMatches( int& count ) const override;
	virtual SharedPointer parseNext( const std::string& document ) const override;

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_VALUE_LEXEME_H

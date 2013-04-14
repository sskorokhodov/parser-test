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
	NameLexeme( const NameLexeme& ) = delete;
	NameLexeme& operator =( const NameLexeme& ) = delete;
	virtual ~NameLexeme() noexcept = default;

	virtual Node< int >& applyTo( Node< int >& node ) const override;
	virtual LexemeType getType() const override;
	virtual void changeExpectedMatches( int& count ) const override;
	virtual SharedPointer parseNext( const std::string& document ) const override;

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_NAME_LEXEME_H

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
	ListEndLexeme( const ListEndLexeme& ) = delete;
	ListEndLexeme& operator =( const ListEndLexeme& ) = delete;
	virtual ~ListEndLexeme() noexcept = default;

	virtual Node& applyTo( Node& node ) const override;
	virtual LexemeType getType() const override;
	virtual void changeExpectedMatches( int& count ) const override;
	virtual SharedPointer parseNext( const std::string& document ) const override;

private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_LIST_END_LEXEME_H

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
	virtual ~AssignLexeme();

	virtual Node* applyTo( Node* node ) const;
	virtual LexemeType::Type getType() const;
	virtual void changeExpectedMatches( int& count ) const;

	virtual Lexeme* parseNext( const std::string& document );

private :
	AssignLexeme( const AssignLexeme& );
	AssignLexeme& operator =( const AssignLexeme& );
	
private :
	StringConstIterator begin_;
	StringConstIterator end_;
};


} // rstyle

#endif // RSTYLE_PARSER_ASSIGN_LEXEME_H

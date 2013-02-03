// LexemesList.h

#ifndef RSTYLE_PARSER_LEXEMES_LIST_H
#define RSTYLE_PARSER_LEXEMES_LIST_H

#include <vector>

#include <Rstyle/Parser/Lexeme.h>



namespace rstyle
{


class LexemesList
{
public :
	LexemesList();
	virtual ~LexemesList();

	void read( const std::string& document );
	void fillNode( Node& node );

private :
	LexemesList( const LexemesList& );
	LexemesList& operator =( const LexemesList& );

private :
	typedef std::vector< Lexeme* > LexemesVector;
	typedef LexemesVector::iterator LexemesIterator;
	LexemesVector lexemes_;
};


} // rstyle

#endif // RSTYLE_PARSER_LEXEMES_LIST_H

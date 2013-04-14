// LexemesList.h

#ifndef RSTYLE_PARSER_LEXEMES_LIST_H
#define RSTYLE_PARSER_LEXEMES_LIST_H

#include <vector>

#include <Rstyle/Parser/Lexeme.h>



namespace rstyle
{


class LexemesList
{
private :
	typedef std::vector< Lexeme::SharedPointer > LexemesVector;

public :
	explicit LexemesList( const std::string& document );
	LexemesList( const LexemesList& ) = delete;
	LexemesList& operator =( const LexemesList& ) = delete;
	virtual ~LexemesList() = default;

	virtual typename Node< int >::SharedPointer fillTree() const;

private :
	static LexemesVector read( const std::string& document );

private :
	const LexemesVector lexemes_;
};


} // rstyle

#endif // RSTYLE_PARSER_LEXEMES_LIST_H

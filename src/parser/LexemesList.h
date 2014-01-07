// LexemesList.h

#ifndef PARSER_PARSER_LEXEMES_LIST_H
#define PARSER_PARSER_LEXEMES_LIST_H

#include <vector>

#include <parser/lexemes/Lexeme.h>



namespace parser
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

	virtual void fillTree( BaseNode& root) const;

private :
	static LexemesVector read( const std::string& document );

private :
	const LexemesVector lexemes_;
};


} // parser

#endif // PARSER_PARSER_LEXEMES_LIST_H

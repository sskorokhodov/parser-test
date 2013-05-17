// Exceptions.h

#ifndef RSTYLE_PARSER_EXCEPTIONS_H
#define RSTYLE_PARSER_EXCEPTIONS_H

#include <stdexcept>
#include <string>



namespace rstyle
{


/**
 * @brief Represents all errors found in parsed document.
 */
class ParseException : public std::logic_error
{
public :
	explicit ParseException( const std::string& message ) :
		logic_error{ message }
	{
	}

	virtual ~ParseException() noexcept = default;
};



/**
 * @brief Represents lexical errors found in parsed document.
 *
 * Lexical error means incorrect/unsupported lexeme content.
 *
 * Example: new line in value lexeme.
 */
class LexicalException : public ParseException
{
public :
	explicit LexicalException( const std::string& message ) :
		ParseException{ message }
	{
	}

	virtual ~LexicalException() noexcept = default;
};



/**
 * @brief Represents syntax errors found in parsed document.
 *
 * Syntax error in most cases means incorrect lexeme position or expected lexeme absence.
 *
 * Example: matching brace absence.
 */
class SyntaxException : public ParseException
{
public :
	explicit SyntaxException( const std::string& message ) :
		ParseException{ message }
	{
	}

	virtual ~SyntaxException() noexcept = default;
};


} // rstyle

#endif // RSTYLE_PARSER_EXCEPTIONS_H

// Exceptions.h

#ifndef RSTYLE_PARSER_EXCEPTIONS_H
#define RSTYLE_PARSER_EXCEPTIONS_H

#include <stdexcept>
#include <string>



namespace rstyle
{


class ParseException : public std::logic_error
{
public :
	explicit ParseException( const std::string& message ) :
		logic_error{ message }
	{
	}

	virtual ~ParseException() noexcept = default;
};



class LexicalException : public ParseException
{
public :
	explicit LexicalException( const std::string& message ) :
		ParseException{ message }
	{
	}

	virtual ~LexicalException() noexcept = default;
};



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

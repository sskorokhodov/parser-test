// AssignLexeme.cpp

#include <Rstyle/Parser/AssignLexeme.h>

#include <Rstyle/Parser/ValueLexeme.h>
#include <Rstyle/Parser/ListBeginLexeme.h>
#include <Rstyle/Parser/Exceptions.h>



namespace rstyle
{


AssignLexeme::AssignLexeme( const StringConstIterator& iStart, const std::string& document )
	: begin_{ iStart }
	, end_{ document.end() }
{
	begin_ = skipSpaces( iStart, document );
	if ( begin_ != document.end() )
	{
		if ( *begin_ != '=' )
		{
			throw SyntaxException{ "Assing lexeme '=' expected" };
		}
		end_ = begin_ + 1;
	}
}



Lexeme::SharedPointer
AssignLexeme::parseNext( const std::string& document ) const
{
	StringConstIterator iLexemeBegin = skipSpaces( end_, document );
	if ( iLexemeBegin != document.end() )
	{
		if ( *iLexemeBegin == '"' )
		{
			return std::make_shared< ValueLexeme >( iLexemeBegin, document );
		}
		else if ( *iLexemeBegin == '{' )
		{
			return std::make_shared< ListBeginLexeme >( iLexemeBegin, document );
		}
	}
	throw SyntaxException{ "Value or list begining expected after '=' lexeme" };
}



Node&
AssignLexeme::applyTo( Node& node ) const
{
	return node;
}



LexemeType
AssignLexeme::getType() const
{
	return LexemeType::ASSIGN;
}



void
AssignLexeme::changeExpectedMatches( int& ) const
{
}


} // rstyle

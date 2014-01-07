// AssignLexeme.cpp

#include <parser/Exceptions.h>
#include <parser/lexemes/AssignLexeme.h>
#include <parser/lexemes/ValueLexeme.h>
#include <parser/lexemes/ListBeginLexeme.h>



namespace parser
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



BaseNode&
AssignLexeme::applyTo( BaseNode& node ) const
{
	return node;
}



LexemeType
AssignLexeme::getType() const
{
	return LexemeType::ASSIGN;
}



int
AssignLexeme::changeExpectedMatches( int count ) const
{
	return count;
}


} // parser

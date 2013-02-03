// AssignLexeme.cpp

#include <Rstyle/Parser/AssignLexeme.h>

#include <Rstyle/Parser/ValueLexeme.h>
#include <Rstyle/Parser/ListBeginLexeme.h>
#include <Rstyle/Parser/Exceptions.h>



namespace rstyle
{


AssignLexeme::AssignLexeme( const StringConstIterator& iStart, const std::string& document ) :
	begin_( iStart ),
	end_( document.end() )
{
	begin_ = skipSpaces( iStart, document );
	if ( begin_ != document.end() )
	{
		if ( *begin_ != '=' )
		{
			throw SyntaxException( "Assing lexeme '=' expected" );
		}
		end_ = begin_ + 1;
	}
}



AssignLexeme::~AssignLexeme() 
{
}



Lexeme* 
AssignLexeme::parseNext( const std::string& document )
{
	StringConstIterator iLexemeBegin = skipSpaces( end_, document );
	if ( iLexemeBegin != document.end() )
	{
		if ( *iLexemeBegin == '"' )
		{
			return new ValueLexeme( iLexemeBegin, document ); 
		}
		else if ( *iLexemeBegin == '{' )
		{
			return new ListBeginLexeme( iLexemeBegin, document );
		}
	}
	throw SyntaxException( "Value or list begining expected after '=' lexeme" );
}



Node* 
AssignLexeme::applyTo( Node* node ) const
{
	return node;
}



LexemeType::Type
AssignLexeme::getType() const
{
	return LexemeType::ASSIGN;
}



void 
AssignLexeme::changeExpectedMatches( int& ) const
{
}


} // rstyle

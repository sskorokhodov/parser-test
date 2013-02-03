// ListBeginLexeme.cpp

#include <Rstyle/Parser/ListBeginLexeme.h>

#include <Rstyle/Parser/ListEndLexeme.h>
#include <Rstyle/Parser/NameLexeme.h>
#include <Rstyle/Parser/Exceptions.h>



namespace rstyle
{


ListBeginLexeme::ListBeginLexeme( 
	const StringConstIterator& iStart, const std::string& document 
) :
	begin_( iStart ),
	end_( document.end() )
{
	begin_ = skipSpaces( iStart, document );
	if ( begin_ != document.end() )
	{
		if ( *begin_ != '{' )
		{
			throw SyntaxException( "List begin lexeme '{' expected" );
		}
		end_ = begin_ + 1;
	}
}
	


ListBeginLexeme::~ListBeginLexeme() 
{
}



Node* 
ListBeginLexeme::applyTo( Node* node ) const
{
	return node;
}



Lexeme* 
ListBeginLexeme::parseNext( const std::string& document )
{
	static const LexemePattern alphaPattern( 'A', 'z' );

	StringConstIterator iLexemeBegin = skipSpaces( end_, document );
	if ( iLexemeBegin != document.end() )
	{
		if ( alphaPattern.isMatch( *iLexemeBegin ) )
		{
			return new NameLexeme( iLexemeBegin, document );
		}
		else if ( *iLexemeBegin == '}' )
		{
			return new ListEndLexeme( iLexemeBegin, document );
		}
	}
	throw SyntaxException( "Name or list end expected after '{' lexeme" );
}



LexemeType::Type
ListBeginLexeme::getType() const
{
	return LexemeType::LIST;
}



void 
ListBeginLexeme::changeExpectedMatches( int& count ) const
{
	++count;
}


} // rstyle

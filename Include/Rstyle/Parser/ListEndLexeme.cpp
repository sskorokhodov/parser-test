// ListEndLexeme.cpp

#include <Rstyle/Parser/ListEndLexeme.h>

#include <Rstyle/Parser/NameLexeme.h>
#include <Rstyle/Parser/Exceptions.h>



namespace rstyle
{


ListEndLexeme::ListEndLexeme( 
	const StringConstIterator& iStart, const std::string& document 
) :
	begin_( iStart ),
	end_( document.end() )
{
	begin_ = skipSpaces( iStart, document );
	if ( begin_ != document.end() )
	{
		if ( *begin_ != '}' )
		{
			throw SyntaxException( "List end lexeme '}' expected" );
		}
		end_ = begin_ + 1;
	}
}



ListEndLexeme::~ListEndLexeme() 
{
}



Node* 
ListEndLexeme::applyTo( Node* node ) const
{
	Node* parent = node->getParent();
	return parent;
}



Lexeme* 
ListEndLexeme::parseNext( const std::string& document )
{
	static const LexemePattern alphaPattern( 'A', 'z' );

	StringConstIterator iLexemeBegin = skipSpaces( end_, document );
	if ( iLexemeBegin != document.end() )
	{
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
		throw SyntaxException( "Name or list end expected after '}' lexeme" );
	}
	return 0;
}



LexemeType::Type
ListEndLexeme::getType() const
{
	return LexemeType::LIST;
}



void 
ListEndLexeme::changeExpectedMatches( int& count ) const
{
	--count;
}


} // rstyle

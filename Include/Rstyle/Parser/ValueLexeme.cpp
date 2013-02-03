// ValueLexeme.cpp

#include <Rstyle/Parser/ValueLexeme.h>

#include <Rstyle/Parser/NameLexeme.h>
#include <Rstyle/Parser/ListEndLexeme.h>
#include <Rstyle/Parser/Exceptions.h>



namespace rstyle
{


ValueLexeme::ValueLexeme( const StringConstIterator& iStart, const std::string& document ) :
	begin_( iStart ),
	end_( document.end() )
{
	begin_ = skipSpaces( iStart, document );
	if ( begin_ != document.end() )
	{
		++begin_;
		end_ = begin_;
		while ( end_ != document.end() )
		{
			char symbol = *end_;
			if ( symbol == '"' )
			{
				break;
			}
			else if ( (symbol == '\n') || (symbol == '\r') )
			{
				throw LexicalException( "Unexpected value end on new line. Value could not be multiline." );
			}
			++end_;
		}
	}
}



ValueLexeme::~ValueLexeme() 
{
}



Node* 
ValueLexeme::applyTo( Node* node ) const
{
	node->setValue( std::string( begin_, end_ ) );
	Node* parent = node->getParent();
	return parent;
}



Lexeme* 
ValueLexeme::parseNext( const std::string& document )
{
	static const LexemePattern alphaPattern( 'A', 'z' );

	StringConstIterator iLexemeBegin = skipSpaces( end_ + 1, document );
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
	throw SyntaxException( "Value or list begining expected after '=' lexeme" );
}



LexemeType::Type
ValueLexeme::getType() const
{
	return LexemeType::VALUE;
}



void 
ValueLexeme::changeExpectedMatches( int& ) const
{
}


} // rstyle

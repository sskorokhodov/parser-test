// NameLexeme.cpp

#include <Rstyle/Parser/NameLexeme.h>

#include <Rstyle/Parser/AssignLexeme.h>



namespace rstyle
{


NameLexeme::NameLexeme( const StringConstIterator& iStart, const std::string& document ) :
	begin_( iStart ),
	end_( document.end() )
{
	static const LexemePattern alphaPattern( 'A', 'z' );
	static const LexemePattern numericPattern( '0', '9' );

	begin_ = skipSpaces( iStart, document );
	if ( begin_ != document.end() )
	{
		end_ = begin_ + 1;
		while ( end_ != document.end() )
		{
			char symbol = *end_;
			if ( !alphaPattern.isMatch( symbol ) && !numericPattern.isMatch( symbol ) )
			{
				break;
			}
			++end_;
		}
	}
}



NameLexeme::~NameLexeme() 
{
}



Node* 
NameLexeme::applyTo( Node* node ) const
{
	Node* subnode = node->addNode( std::string( begin_, end_ ) );
	return subnode;
}



Lexeme* 
NameLexeme::parseNext( const std::string& document )
{
	return new AssignLexeme( end_, document );
}



LexemeType::Type
NameLexeme::getType() const
{
	return LexemeType::NAME;
}



void 
NameLexeme::changeExpectedMatches( int& ) const
{
}


} // rstyle

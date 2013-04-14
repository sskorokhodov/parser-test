// NameLexeme.cpp

#include <Rstyle/Parser/NameLexeme.h>

#include <Rstyle/Parser/AssignLexeme.h>



namespace rstyle
{


NameLexeme::NameLexeme( const StringConstIterator& iStart, const std::string& document )
	: begin_{ iStart }
	, end_{ document.end() }
{
	static const LexemePattern alphaPattern{ 'A', 'z' };
	static const LexemePattern numericPattern{ '0', '9' };

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



Node< int >&
NameLexeme::applyTo( Node< int >& node ) const
{
	auto subnode = node.addNode( std::string( begin_, end_ ) );
	return *subnode;
}



Lexeme::SharedPointer
NameLexeme::parseNext( const std::string& document ) const
{
	return std::make_shared< AssignLexeme >( end_, document );
}



LexemeType
NameLexeme::getType() const
{
	return LexemeType::NAME;
}



void
NameLexeme::changeExpectedMatches( int& ) const
{
}


} // rstyle

// ListEndLexeme.cpp

#include <parser/Exceptions.h>
#include <parser/lexemes/ListEndLexeme.h>
#include <parser/lexemes/NameLexeme.h>



namespace parser
{


ListEndLexeme::ListEndLexeme(
	const StringConstIterator& iStart, const std::string& document
)
	: begin_{ iStart }
	, end_{ document.end() }
{
	begin_ = skipSpaces( iStart, document );
	if ( begin_ != document.end() )
	{
		if ( *begin_ != '}' )
		{
			throw SyntaxException{ "List end lexeme '}' expected" };
		}
		end_ = begin_ + 1;
	}
}



BaseNode&
ListEndLexeme::applyTo( BaseNode& node ) const
{
	return node.getParent();
}



Lexeme::SharedPointer
ListEndLexeme::parseNext( const std::string& document ) const
{
	static const LexemePattern alphaPattern{ 'A', 'z' };

	StringConstIterator iLexemeBegin = skipSpaces( end_, document );
	if ( iLexemeBegin != document.end() )
	{
		if ( iLexemeBegin != document.end() )
		{
			if ( alphaPattern.isMatch( *iLexemeBegin ) )
			{
				return std::make_shared< NameLexeme >( iLexemeBegin, document );
			}
			else if ( *iLexemeBegin == '}' )
			{
				return std::make_shared< ListEndLexeme >( iLexemeBegin, document );
			}
		}
		throw SyntaxException{ "Name or list end expected after '}' lexeme" };
	}
	return Lexeme::null;
}



LexemeType
ListEndLexeme::getType() const
{
	return LexemeType::LIST;
}



int ListEndLexeme::changeExpectedMatches( int count ) const
{
	return --count;
}


} // parser

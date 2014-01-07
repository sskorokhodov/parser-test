// ListBeginLexeme.cpp

#include <parser/Exceptions.h>
#include <parser/lexemes/ListBeginLexeme.h>
#include <parser/lexemes/ListEndLexeme.h>
#include <parser/lexemes/NameLexeme.h>



namespace parser
{


ListBeginLexeme::ListBeginLexeme(
	const StringConstIterator& iStart, const std::string& document
)
	: begin_{ iStart }
	, end_{ document.end() }
{
	begin_ = skipSpaces( iStart, document );
	if ( begin_ != document.end() )
	{
		if ( *begin_ != '{' )
		{
			throw SyntaxException{ "List begin lexeme '{' expected" };
		}
		end_ = begin_ + 1;
	}
}



BaseNode&
ListBeginLexeme::applyTo( BaseNode& node ) const
{
	return node;
}



Lexeme::SharedPointer
ListBeginLexeme::parseNext( const std::string& document ) const
{
	static const LexemePattern alphaPattern{ 'A', 'z' };

	StringConstIterator iLexemeBegin = skipSpaces( end_, document );
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
	throw SyntaxException{ "Name or list end expected after '{' lexeme" };
}



LexemeType
ListBeginLexeme::getType() const
{
	return LexemeType::LIST;
}



int ListBeginLexeme::changeExpectedMatches( int count ) const
{
	return ++count;
}


} // parser

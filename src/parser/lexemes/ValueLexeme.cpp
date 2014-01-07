// ValueLexeme.cpp

#include <parser/Exceptions.h>
#include <parser/lexemes/ValueLexeme.h>
#include <parser/lexemes/NameLexeme.h>
#include <parser/lexemes/ListEndLexeme.h>



namespace parser
{


ValueLexeme::ValueLexeme( const StringConstIterator& iStart, const std::string& document )
	: begin_{ iStart }
	, end_{ document.end() }
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
				throw LexicalException{ "Unexpected value end on new line. Value could not be multiline." };
			}
			++end_;
		}
	}
}



BaseNode&
ValueLexeme::applyTo( BaseNode& node ) const
{
	node.setValue( { begin_, end_ } );
	return node.getParent();
}



Lexeme::SharedPointer
ValueLexeme::parseNext( const std::string& document ) const
{
	static const LexemePattern alphaPattern{ 'A', 'z' };

	StringConstIterator iLexemeBegin = skipSpaces( end_ + 1, document );
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
	throw SyntaxException{ "Value or list begining expected after '=' lexeme" };
}



LexemeType
ValueLexeme::getType() const
{
	return LexemeType::VALUE;
}



int ValueLexeme::changeExpectedMatches( int count ) const
{
	return count;
}


} // parser

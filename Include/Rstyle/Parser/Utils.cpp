// Utils.cpp

#include <Rstyle/Parser/Utils.h>
#include <stdexcept>



namespace rstyle
{


StringConstIterator
skipSpaces( StringConstIterator iStart, const std::string& document )
{
	while ( iStart != document.end() )
	{
		char symbol = *iStart;
		bool isSpace = (symbol == '\t') || (symbol == ' ') || (symbol == '\n') || (symbol == '\r');
		if ( !isSpace )
		{
			return iStart;
		}
		++iStart;
	}

	return document.end();
}





LexemePattern::LexemePattern( char symbol )
	: first_{ symbol }
	, last_{ symbol }
{
}



LexemePattern::LexemePattern( char first, char last )
	: first_{ first }
	, last_{ last }
{
	if ( first_ > last_ )
	{
		throw std::logic_error{ "LexemePattern construction exception" };
	}
}



LexemePattern::LexemePattern( const LexemePattern& pattern )
	: first_{ pattern.first_ }
	, last_{ pattern.last_ }
{
}



bool
LexemePattern::isMatch( char symbol ) const
{
	return ((first_ <= symbol) && (last_ >= symbol));
}


} // rstyle

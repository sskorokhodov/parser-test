// ConvertToString.hpp

#ifndef SIMPLE_CONVERT_TO_STRING_HPP
#define SIMPLE_CONVERT_TO_STRING_HPP

#include <sstream>



namespace simple
{


template< class T >
std::string
convertToString( const T& value )
{
	std::ostringstream stream;
	stream << value;
	return stream.str();
}


} // simple

#endif // SIMPLE_CONVERT_TO_STRING_HPP

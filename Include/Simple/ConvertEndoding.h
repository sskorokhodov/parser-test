// ConvertEncoding.h

#ifndef SIMPLE_CONVERT_ENCODING_H
#define SIMPLE_CONVERT_ENCODING_H

#include <string>



namespace simple
{


std::string convertAnsiToOem( const std::string& ansi );
std::string convertUtf8ToOem( const std::string& utf8 );

} // simple

#endif // SIMPLE_CONVERT_ENCODING_H

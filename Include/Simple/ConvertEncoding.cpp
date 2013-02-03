// ConvertEncoding.h

#include <Simple/ConvertEndoding.h>

#include <Windows.h>



namespace simple
{


std::string 
convertAnsiToOem( const std::string& ansi )
{
	std::string oem( ansi.size(), '\0' );
	::AnsiToOem( ansi.c_str(), const_cast< char* >( oem.c_str() ) );
	return oem;
}


} // simple

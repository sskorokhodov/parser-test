// ConvertEncoding.h

#include <vector>

//#include <Windows.h>

#include <utils/ConvertEndoding.h>



namespace simple
{


std::string
convertAnsiToOem( const std::string& ansi )
{
	/*
	std::string oem( ansi.size(), '\0' );
	::AnsiToOem( ansi.c_str(), const_cast< char* >( oem.c_str() ) );
	return oem;
	*/
	return ansi;
}


std::string
convertUtf8ToOem( const std::string& utf8 )
{
	/*
	int nBytes = ::MultiByteToWideChar( CP_UTF8, 0, utf8.c_str(), -1, 0, 0 );
	std::vector< wchar_t > wbuffer( nBytes );
	::MultiByteToWideChar( CP_UTF8, 0, utf8.c_str(), -1, &wbuffer.front(), nBytes );
	int nChars = ::WideCharToMultiByte( CP_UTF8, 0, &wbuffer.front(), -1, 0, 0, 0, 0 );

	std::string oem;
	oem.resize( nChars );
	::WideCharToMultiByte(
		CP_OEMCP, 0, &wbuffer.front(), -1, const_cast< char* >( oem.c_str() ), nChars, 0, 0 );
	oem.pop_back();

	return oem;
	*/
	return utf8;
}


} // simple

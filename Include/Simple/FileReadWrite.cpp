// FileReadWrite.cpp

#include <Simple/FileReadWrite.h>

#include <fstream>
#include <vector>
#include <stdexcept>



namespace simple
{


std::string 
readFile( const std::string& name )
{
	std::ifstream inputFile( name.c_str(), std::ios_base::binary | std::ios_base::in );
	if ( inputFile.is_open() )
	{
		const size_t bufferSize = 4096 * 1000;
		std::string document;
		std::vector< char > buffer( bufferSize, '\0' );
		size_t nBytesRead = 0;
		while ( !inputFile.eof() ) 
		{
			inputFile.read( &buffer.front(), bufferSize );
			nBytesRead = static_cast< size_t >( inputFile.gcount() );
			document.append( &buffer.front(), nBytesRead );
		}
		return document;
	}
	std::string message = "Could not open file '" + name + "'";
	throw std::logic_error( message.c_str() );
}



void 
writeFile( const std::string& out, const std::string& fileName )
{
	std::ofstream outFile( fileName.c_str(), std::ios_base::out | std::ios_base::out );
	if ( outFile.is_open() )
	{
		outFile.write( out.c_str(), out.size() );
	}
	else
	{
		std::string message = "Could not open file '" + fileName + "'";
		throw std::logic_error( message.c_str() );
	}
}


} // simple

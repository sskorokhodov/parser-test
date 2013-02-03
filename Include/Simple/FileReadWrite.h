// FileReadWrite.h

#ifndef SIMPLE_FILE_READ_WRITE_H
#define SIMPLE_FILE_READ_WRITE_H

#include <string>



namespace simple
{


std::string readFile( const std::string& name );
void writeFile( const std::string& out, const std::string& fileName );


} // simple

#endif // SIMPLE_FILE_READ_WRITE_H

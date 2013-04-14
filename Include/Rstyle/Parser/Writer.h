// Writer.h

#ifndef RSTYLE_PARSER_WRITER_H
#define RSTYLE_PARSER_WRITER_H

#include <string>

#include <Rstyle/Parser/Node.hpp>



namespace rstyle
{


class Writer
{
public :
	virtual ~Writer() = default;

	virtual std::string write( const Node< int >& root ) const = 0;
};


} // rstyle

#endif // RSTYLE_PARSER_WRITER_H

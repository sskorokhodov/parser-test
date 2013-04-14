// Writer.h

#ifndef RSTYLE_PARSER_WRITER_H
#define RSTYLE_PARSER_WRITER_H

#include <string>

#include <Rstyle/Parser/Node.h>



namespace rstyle
{


class Writer
{
public :
	virtual ~Writer() = default;

	virtual std::string write( const Node& root ) const = 0;
};


} // rstyle

#endif // RSTYLE_PARSER_WRITER_H

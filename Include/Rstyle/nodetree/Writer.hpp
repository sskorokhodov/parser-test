// Writer.h

#ifndef RSTYLE_PARSER_WRITER_H
#define RSTYLE_PARSER_WRITER_H

#include <string>

#include <rstyle/nodetree/Node.hpp>



namespace rstyle
{


template< class T >
class Writer
{
public :
	virtual ~Writer() = default;

	virtual std::string write( const Node< T >& root ) const = 0;
};


} // rstyle

#endif // RSTYLE_PARSER_WRITER_H

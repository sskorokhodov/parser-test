// Writer.h

#ifndef RSTYLE_NODESTREE_WRITER_H
#define RSTYLE_NODESTREE_WRITER_H

#include <string>

#include <rstyle/nodestree/Node.hpp>



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

#endif // RSTYLE_NODESTREE_WRITER_H

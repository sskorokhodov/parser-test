// Writer.h

#ifndef PARSER_NODESTREE_WRITER_H
#define PARSER_NODESTREE_WRITER_H

#include <string>

#include <nodestree/Node.hpp>



namespace parser
{


template< class T >
class Writer
{
public :
	virtual ~Writer() = default;

	virtual std::string write( const Node< T >& root ) const = 0;
};


} // parser

#endif // PARSER_NODESTREE_WRITER_H

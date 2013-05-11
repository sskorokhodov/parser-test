// StructureWriter.h

#ifndef RSTYLE_PARSER_STRUCTURE_WRITER_H
#define RSTYLE_PARSER_STRUCTURE_WRITER_H

#include <rstyle/nodestree/Writer.hpp>



/**
 * The namespace containes parser classes.
 */
namespace rstyle
{


/**
 * @brief Produces structure of nodes tree.
 *
 * Produces structure of nodes tree in format:
 *
 *     1, shape, 0
 *     2, type, 1, tetrahedron
 *     3, vertices, 1
 *     ...
 *
 * where comma separated values of one string are:
 * - first value is node index (1,2,3),
 * - second value is node name (shape,type,vertices),
 * - third value is parent node index (0,1,1),
 * - fourth value (*optional*) is node value (tetrahedron).
 */
class StructureWriter : public Writer< int >
{
public :
	StructureWriter() = default;
	StructureWriter( const StructureWriter& ) = delete;
	StructureWriter& operator =( const StructureWriter& ) = delete;
	virtual ~StructureWriter() noexcept = default;

	/**
	 * @brief Produces structure of nodes tree.
	 * @param node - the root of nodes tree to process.
	 * @return Returns string that contains structured view of nodes tree.
	 */
	virtual std::string write( const Node< int >& node ) const override;
};


} // rstyle

#endif // RSTYLE_PARSER_STRUCTURE_WRITER_H

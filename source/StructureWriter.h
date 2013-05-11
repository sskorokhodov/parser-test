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
 * 1, shape, 0\n
 * 2, type, 1, tetrahedron\n
 * 3, vertices, 1\n
 * ...
 *
 * where:\n
 * - first value is node index (1,2,3),\n
 * - second value is node name (shape,type,vertices),\n
 * - third value is parent node index (0,1,1),\n
 * - fourth value is node value (tetrahedron).
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

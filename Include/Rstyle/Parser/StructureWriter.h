// StructureWriter.h

#ifndef RSTYLE_PARSER_STRUCTURE_WRITER_H
#define RSTYLE_PARSER_STRUCTURE_WRITER_H

#include <Rstyle/Parser/Writer.h>



namespace rstyle
{

	
class StructureWriter : public Writer
{
public :
	StructureWriter();
	virtual ~StructureWriter();

	std::string write( const Node& node ) const;

private :
	StructureWriter( const StructureWriter& );
	StructureWriter& operator =( const StructureWriter& );
};


} // rstyle

#endif // RSTYLE_PARSER_STRUCTURE_WRITER_H

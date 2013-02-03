// Process.cpp

#include "Process.h"

#include <Simple/FileReadWrite.h>

#include <Rstyle/Parser/Parser.h>
#include <Rstyle/Parser/NodesTree.h>
#include <Rstyle/Parser/StructureWriter.h>



namespace
{
	class IndexingVisitor : public rstyle::Node::Visitor
	{
	public :
		IndexingVisitor() :
			id_( 1 )
		{
		}

		void accept( rstyle::Node& node )
		{
			node.setId( id_ );
			++id_;
		}

	private :
		size_t id_;
	};
} //



void 
process( const std::string& inputFileName, const std::string& outputFileName )
{
	auto document = simple::readFile( inputFileName );

	rstyle::Parser parser;
	rstyle::NodesTree tree;
	parser.parse( tree, document );

	IndexingVisitor indexator;
	tree.visit( indexator );

	rstyle::StructureWriter writer;
	auto out = writer.write( tree );
	simple::writeFile( out, outputFileName );
}

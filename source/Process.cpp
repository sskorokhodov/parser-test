// Process.cpp

#include "Process.h"

#include <simple/FileReadWrite.h>

#include <rstyle/parser/Parser.h>

#include <rstyle/nodestree/NodesTree.hpp>
#include "StructureWriter.h"

#include <iostream>



namespace
{
	void printIds( const rstyle::Node< int >& node )
	{
		for ( const auto& subnode : node )
		{
			std::cout << subnode.getData() << std::endl;
			printIds( subnode );
		}
	}
} //



void
process( const std::string& inputFileName, const std::string& outputFileName )
{
	auto document = simple::readFile( inputFileName );

	rstyle::Parser parser;
	rstyle::NodesTree< int > root;
	parser.parse( document, root );

	int id = 1;
	root.visitWithFunction( [&id]( rstyle::Node< int >& node ){ node.setData( id ); ++id; } );

	std::cout << root.countSubnodes() << " nodes:" << std::endl;
	::printIds( root );

	rstyle::StructureWriter writer;
	auto out = writer.write( root );
	simple::writeFile( out, outputFileName );
}

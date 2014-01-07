// Process.cpp

#include "Process.h"

#include <utils/FileReadWrite.h>

#include <parser/Parser.h>

#include <nodestree/NodesTree.hpp>
#include "StructureWriter.h"

#include <iostream>



namespace
{
	void printIds( const parser::Node< int >& node )
	{
		for ( const auto& subnode : node )
		{
			std::cout << subnode.getData() << std::endl;
			printIds( subnode );
		}
	}
} //



std::string
convertToStructuredView( const std::string& document)
{
	parser::Parser parser;
	parser::NodesTree< int > root;
	parser.parse( document, root );

	int id = 1;
	root.visitWithFunction( [&id]( parser::Node< int >& node ){ node.setData( id ); ++id; } );

	std::cout << root.countSubnodes() << " nodes:" << std::endl;
	::printIds( root );

	parser::StructureWriter writer;
	return writer.write( root );
}



void
process( const std::string& inputFileName, const std::string& outputFileName )
{
	auto document = simple::readFile( inputFileName );
	auto out = convertToStructuredView(document);
	simple::writeFile( out, outputFileName );
}

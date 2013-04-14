// Process.cpp

#include "Process.h"

#include <Simple/FileReadWrite.h>

#include <Rstyle/Parser/Parser.h>
#include <Rstyle/Parser/StructureWriter.h>

#include <iostream>



namespace
{
	class IndexingVisitor : public rstyle::Node< int >::Visitor
	{
	public :
		IndexingVisitor()
			: id_{ START_ID }
		{
		}

		void accept( rstyle::Node< int >& node ) override
		{
			node.getData() = id_;
			++id_;
		}

	private :
		static const size_t START_ID = 1;
		size_t id_;
	};
} //



void printIds( const rstyle::Node< int >& node )
{
	for ( const auto& subnode : node )
	{
		std::cout << subnode.getData() << std::endl;
		printIds( subnode );
	}
}



void
process( const std::string& inputFileName, const std::string& outputFileName )
{
	auto document = simple::readFile( inputFileName );

	rstyle::Parser parser;
	auto root = parser.parse( document );

	IndexingVisitor indexator;
	root->visit( indexator );

	::printIds( *root );

	rstyle::StructureWriter writer;
	auto out = writer.write( *root );
	simple::writeFile( out, outputFileName );
}

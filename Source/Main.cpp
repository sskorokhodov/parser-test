// Main.cpp

#include <iostream>

#include <Simple/ConvertEndoding.h>
#include <Simple/CommandLineOptions.h>

#include <Rstyle/Parser/Exceptions.h>

#include "Process.h"



void printHelp();



int main( int argc, char* argv[] )
{
	try {
		simple::CommandLineOptions options( "-" );
		options.addKey( "i" );
		options.addKey( "o" );
		options.parse( argc, argv );

		if ( options.has( "i" ) )
		{
            std::string inputFileName = options.get( "i" );
            std::string outputFileName = options.get( "o", "out.txt" );
			::process( inputFileName, outputFileName );
		}
		else
		{
            ::printHelp();
		}
	}
	catch ( const simple::CommandLineOptions::ParseException& e ) {
		std::cerr << e.what() << std::endl;
		std::cerr << simple::convertAnsiToOem( "Неверные аргументы командной строки" ) << std::endl;
		printHelp();
		return 4;
	}
	catch ( const rstyle::ParseException& e ) {
		std::cerr << e.what() << std::endl;
		std::cerr << simple::convertAnsiToOem( "Неверный формат данных" ) << std::endl;
		return 3;
	}
	catch ( const std::exception& e ) {
		std::cerr << e.what() << std::endl;
		return 2;
	}
	catch ( ... ) {
		std::cerr << "Unexpected error" << std::endl;
		return 1;
	}
	return 0;
}



void printHelp()
{
	static const std::string help = simple::convertAnsiToOem(
		"R-style test data format parser help:\n"
		"\n"
		"Converts data in R-style test data format from input file into\n"
		"structure view and put it to output file.\n"
		"If no output file specified \"output.txt\" is used by default.\n"
		"Warning! Output file would be replaced if exist!\n"
		"\n"
		"Format:\n"
		"\tRStyleParser.exe -i input [ -o output ]\n"
		"\n"
		"Options:\n"
		"\t-i\t: input file name\n"
		"\t-o\t: output file name\n"
	);
	std::cout << help;
}


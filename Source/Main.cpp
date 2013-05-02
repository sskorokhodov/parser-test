// Main.cpp

#include <iostream>

#include <Simple/ConvertEndoding.h>
#include <Simple/CommandLineOptions.h>

#include <rstyle/parser/Exceptions.h>

#include "Process.h"



namespace
{
	enum class ExecutionResultCode : int
	{
		SUCCESS = 0,
		UNRECOGNIZED,
		UNEXPECTED,
		PARSING,
		COMMAND_LINE_ARGUMENTS
	};



	void printHelp()
	{
		static const auto help = simple::convertUtf8ToOem(
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



	simple::CommandLineOptions getCommandLineOptions( int argc, char* argv[] )
	{
		simple::CommandLineOptions options{ "-" };
		options.addKey( "i" );
		options.addKey( "o" );
		options.parse( argc, argv );
		return options;
	}
} //



int main( int argc, char* argv[] )
{
	try
	{
		auto options = ::getCommandLineOptions( argc, argv );
		auto inputFileName = options.get( "i" );
		auto outputFileName = options.get( "o", "out.txt" );

		::process( inputFileName, outputFileName );
	}
	catch ( const simple::CommandLineOptions::ParseException& e )
	{
		std::cerr << e.what() << std::endl;
		std::cerr << simple::convertUtf8ToOem( u8"Неверные аргументы командной строки" ) << std::endl;
		::printHelp();
		return static_cast< int >( ExecutionResultCode::COMMAND_LINE_ARGUMENTS );
	}
	catch ( const rstyle::ParseException& e )
	{
		std::cerr << e.what() << std::endl;
		std::cerr << simple::convertUtf8ToOem( u8"Неверный формат данных" ) << std::endl;
		return static_cast< int >( ExecutionResultCode::PARSING );
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
		return static_cast< int >( ExecutionResultCode::UNEXPECTED );
	}
	catch ( ... )
	{
		std::cerr << "Unrecognized error" << std::endl;
		return static_cast< int >( ExecutionResultCode::UNRECOGNIZED );
	}
	return static_cast< int >( ExecutionResultCode::SUCCESS );
}

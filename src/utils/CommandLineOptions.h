// CommandLineOptions.h

#ifndef SIMPLE_COMMAND_LINE_OPTIONS_H
#define SIMPLE_COMMAND_LINE_OPTIONS_H

#include <string>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>



namespace simple
{


class CommandLineOptions
{
public :
	class ParseException;

public :
	explicit CommandLineOptions( const std::string& nameSign );
	CommandLineOptions(const CommandLineOptions& );
	CommandLineOptions( const CommandLineOptions&& ) noexcept;
	CommandLineOptions& operator =( const CommandLineOptions& ) = delete;
	virtual ~CommandLineOptions() = default;

	std::string get( const std::string& key ) const;
	std::string get( const std::string& key, const std::string& defaultValue ) const;
	std::string getExecutableName() const;
	bool has( const std::string& key ) const;
	bool isEmpty() const;

	void parse( int argc, char* argv[] );
	void addKey( const std::string& key );

private :
	bool isKey( const std::string& token ) const;
	void checkIfKeyAllowed( const std::string& key ) const;
	static bool isStartWith( const std::string& data, const std::string& start );

private :
	typedef std::map< std::string, std::string > OptionsMap;
	typedef std::set< std::string > KeysSet;

	KeysSet keys_;
	OptionsMap options_;
	std::string executableName_;
	const std::string keySign_;
};



class CommandLineOptions::ParseException : public std::logic_error
{
public :
	explicit ParseException( const std::string& message ) :
		logic_error( message )
	{
	}

	virtual ~ParseException() noexcept = default;
};


} // simple

#endif // SIMPLE_COMMAND_LINE_OPTIONS_H

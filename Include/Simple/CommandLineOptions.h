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
	CommandLineOptions( const CommandLineOptions& );
	virtual ~CommandLineOptions();
	
	bool isEmpty() const;
	bool has( const std::string& key ) const;
	std::string get( const std::string& key ) const;
	std::string get( const std::string& key, const std::string& defaultValue ) const;
	std::string getExecutableName() const;

	void addKey( const std::string& key );
	void parse( int argc, char* argv[] );

private :
	CommandLineOptions& operator =( const CommandLineOptions& );

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
        logic_error( message.c_str() )
	{
	}

    virtual ~ParseException() throw() {}
};


} // simple

#endif // SIMPLE_COMMAND_LINE_OPTIONS_H

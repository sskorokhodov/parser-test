// CommandLineOptions.cpp

#include <assert.h>

#include <utils/CommandLineOptions.h>



namespace simple
{


CommandLineOptions::CommandLineOptions( const std::string& keySign )
	: keySign_{ keySign }
{
	assert( !keySign_.empty() && "CommandLineOptions creation error: key sign should not be empty" );
}



CommandLineOptions::CommandLineOptions( const CommandLineOptions& options )
	: keys_{ options.keys_ }
	, options_{ options.options_ }
	, executableName_{ options.executableName_ }
	, keySign_{ options.keySign_ }
{
}



CommandLineOptions::CommandLineOptions(const CommandLineOptions&& options ) noexcept
	: keys_{ std::move( options.keys_ ) }
	, options_{ std::move( options.options_ ) }
	, executableName_{ std::move( options.executableName_ ) }
	, keySign_{ std::move( options.keySign_ ) }
{
}



void
CommandLineOptions::addKey( const std::string& key )
{
	keys_.insert( keySign_ + key );
}



void
CommandLineOptions::parse( int argc, char* argv[] )
{
	if ( argc > 0 )
	{
		executableName_ = std::string{ argv[ 0 ] };

		std::string currentKey;
		for ( int i = 1; i < argc; ++i )
		{
			std::string token{ argv[ i ] };
			if ( this->isKey( token ) )
			{
				this->checkIfKeyAllowed( token );
				currentKey = token;
				options_[ currentKey ];
			}
			else if ( !currentKey.empty() )
			{
				options_[ currentKey ] = token;
			}
		}
	}
}



bool
CommandLineOptions::isKey( const std::string& token ) const
{
	return isStartWith( token, keySign_ );
}



void
CommandLineOptions::checkIfKeyAllowed( const std::string& key ) const
{
	bool isAllowed = (keys_.find( key ) != keys_.end());
	if ( !isAllowed )
	{
		throw ParseException{ "Unexpected option key '" + key + "'" };
	}
}



bool
CommandLineOptions::isStartWith( const std::string& data, const std::string& start )
{
	if ( data.size() >= start.size() )
	{
		return data.substr( 0, start.size() ) == start;
	}
	return false;
}



bool
CommandLineOptions::has( const std::string& key ) const
{
	return (options_.find( keySign_ + key ) != options_.end());
}



std::string
CommandLineOptions::get( const std::string& key ) const
{
	auto iOption = options_.find( keySign_ + key );
	if ( iOption != options_.end() )
	{
		if ( !iOption->second.empty() )
		{
			return iOption->second;
		}
	}
	throw ParseException{ "Option '" + key + "' is not set" };
}



std::string
CommandLineOptions::get( const std::string& key, const std::string& defaultValue ) const
{
	auto iOption = options_.find( keySign_ + key );
	if ( iOption != options_.end() )
	{
		if ( !iOption->second.empty() )
		{
			return iOption->second;
		}
	}
	return defaultValue;
}



std::string
CommandLineOptions::getExecutableName() const
{
	return executableName_;
}



bool
CommandLineOptions::isEmpty() const
{
	return options_.empty();
}


} // simple

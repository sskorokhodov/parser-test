// StructureWriter.cpp

#include "StructureWriter.h"

#include <utils/ConvertToString.hpp>



namespace parser
{


namespace
{
	class InfoCollectingNodeVisitor : public parser::Node< int >::ConstVisitor
	{
	public :
		void accept( const Node< int >& node )
		{
			info_ += simple::convertToString( node.getData() );
			info_ += ", " + simple::convertToString( node.getParent().getData() );
			info_ += ", " + node.getName();
			if ( !node.isComposite() )
			{
				info_ += ", " + node.getValue();
			}
			info_ += "\n";
		}

		std::string getInfo() const
		{
			return info_;
		}

	private :
		std::string info_;
	};
} //



std::string
StructureWriter::write( const Node< int >& node ) const
{
	InfoCollectingNodeVisitor infoCollector;
	node.visit( infoCollector );
	return infoCollector.getInfo();
}


} // parser

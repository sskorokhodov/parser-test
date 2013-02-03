// StructureWriter.cpp

#include <Rstyle/Parser/StructureWriter.h>

#include <Simple/ConvertToString.hpp>



namespace rstyle
{

	
namespace
{
	class InfoCollectingNodeVisitor : public rstyle::Node::ConstVisitor
	{
	public :
		void accept( const rstyle::Node& node )
		{
			info_ += simple::convertToString( node.getId() );
			info_ += ", " + simple::convertToString( node.getParent()->getId() );
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



StructureWriter::StructureWriter()
{
}



StructureWriter::~StructureWriter()
{
}



std::string 
StructureWriter::write( const Node& node ) const
{
	InfoCollectingNodeVisitor infoCollector;
	node.visit( infoCollector );
	return infoCollector.getInfo();
}


} // rstyle

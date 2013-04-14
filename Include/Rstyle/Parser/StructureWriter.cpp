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
			info_ += ", " + simple::convertToString( node.getParent().getId() );
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



/**
 * @brief Produces structure of nodes tree.
 * @param node - the root of nodes tree to process.
 * @return Returns string that contains structured view of nones tree.
 */
std::string
StructureWriter::write( const Node& node ) const
{
	InfoCollectingNodeVisitor infoCollector;
	node.visit( infoCollector );
	return infoCollector.getInfo();
}


} // rstyle

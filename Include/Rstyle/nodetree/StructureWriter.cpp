// StructureWriter.cpp

#include <rstyle/nodetree/StructureWriter.h>

#include <Simple/ConvertToString.hpp>



namespace rstyle
{


namespace
{
	class InfoCollectingNodeVisitor : public rstyle::Node< int >::ConstVisitor
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



/**
 * @brief Produces structure of nodes tree.
 * @param node - the root of nodes tree to process.
 * @return Returns string that contains structured view of nodes tree.
 */
std::string
StructureWriter::write( const Node< int >& node ) const
{
	InfoCollectingNodeVisitor infoCollector;
	node.visit( infoCollector );
	return infoCollector.getInfo();
}


} // rstyle

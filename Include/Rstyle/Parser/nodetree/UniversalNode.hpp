// UniversalNode.hpp

#ifndef RSTYLE_PARSER_UNIVERSAL_NODE_HPP
#define RSTYLE_PARSER_UNIVERSAL_NODE_HPP

#include <vector>

#include <rstyle/parser/nodetree/Node.hpp>



namespace rstyle
{


template< class T >
class UniversalNode : public Node< T >
{
private :
	typedef std::vector< typename Node< T >::SharedPointer > NodesVector;

protected :
	class IteratorImpl : public Node< T >::IteratorImpl
	{
	public :
		IteratorImpl( const typename NodesVector::const_iterator& subnodesIterator, const NodesVector* subnodes )
			: subnodesIterator_{ subnodesIterator }
			, subnodes_{ subnodes }
		{
		}

		virtual bool operator !=( const typename Node< T >::IteratorImpl& other ) const noexcept override
		{
			if ( subnodesIterator_ ==  subnodes_->end() )
			{
				return Node< T >::null != *other;
			}
			return *subnodesIterator_ != *other;
		}

		virtual const typename Node< T >::SharedPointer& operator *() const noexcept override
		{
			if ( subnodesIterator_ ==  subnodes_->end() )
			{
				return Node< T >::null;
			}
			return *subnodesIterator_;
		}

		virtual IteratorImpl& operator ++() override
		{
			++subnodesIterator_;
			return *this;
		}

	private :
		typename NodesVector::const_iterator subnodesIterator_;
		const NodesVector* subnodes_;
	};

public :
	UniversalNode( const std::string& name, Node< T >* parent )
		: name_{ name }
		, parent_{ parent }
		, id_{ 0 }
	{
	}



	UniversalNode( const UniversalNode& ) = delete;



	UniversalNode& operator =( const UniversalNode& ) = delete;



	virtual ~UniversalNode() noexcept = default;





	virtual typename Node< T >::DataType& getData() override
	{
		return id_;
	}



	virtual const typename Node< T >::DataType& getData() const override
	{
		return id_;
	}



	virtual std::string getName() const
	{
		return name_;
	}



	virtual bool isComposite() const
	{
		return !subnodes_.empty();
	}



	virtual std::string getValue() const
	{
		return value_;
	}



	virtual void setValue( const std::string& value )
	{
		if ( !subnodes_.empty() )
		{
			throw std::logic_error{ "Could not add value to composite node" };
		}
		value_ = value;
	}



	virtual typename Node< T >::SharedPointer addNode( const std::string& name )
	{
		value_.clear();
		auto subnode = std::make_shared< UniversalNode >( name, this );
		subnodes_.push_back( subnode );
		return subnode;
	}



	virtual Node< T >& getParent() const
	{
		return *parent_;
	}



	virtual void visit( typename Node< T >::Visitor& visitor )
	{
		visitor.accept( *this );
		for ( auto& node : subnodes_ )
		{
			node->visit( visitor );
		}
	}



	virtual void visit( typename Node< T >::ConstVisitor& visitor ) const
	{
		visitor.accept( *this );
		for ( const auto& node : subnodes_ )
		{
			node->visit( visitor );
		}
	}



	virtual typename Node< T >::Iterator begin() const override
	{
		return typename Node< T >::Iterator{ std::make_shared< IteratorImpl >( subnodes_.begin(), &subnodes_ ) };
	}



	virtual typename Node< T >::Iterator end() const override
	{
		return typename Node< T >::Iterator{ std::make_shared< IteratorImpl >( subnodes_.end(), &subnodes_ ) };
	}



private :
	const std::string name_;
	Node< T >* const parent_;
	std::string value_;
	NodesVector subnodes_;
	typename Node< T >::DataType id_;
};


} // rstyle

#endif // RSTYLE_PARSER_UNIVERSAL_NODE_HPP

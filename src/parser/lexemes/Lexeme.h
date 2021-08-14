// Lexeme.h

#ifndef PARSER_PARSER_LEXEME_H
#define PARSER_PARSER_LEXEME_H

#include <memory>

#include <nodestree/BaseNode.hpp>



namespace parser
{


/**
 * @brief Supported lexeme type identificators
 */
enum class LexemeType
{
	NAME,
	LIST,
	ASSIGN,
	VALUE
};


/**
 * @brief Common interface for all lexemes.
 */
class Lexeme
{
public :
	typedef std::shared_ptr< Lexeme > SharedPointer;

public :
	virtual ~Lexeme() = default;

	/**
	 * @brief Parses the next lexeme.
	 *
	 * @param document - the document left.
	 * @return The next lexeme in the document.
	 */
	virtual SharedPointer parseNext( const std::string& document ) const = 0;

	/**
	 * @brief Modifies the node according to lexeme's semantics (set value, add subnode, etc.)
	 *
	 * @param node - the node to apply the lexeme to.
	 * @return The node to apply the next lexeme to.
	 */
	virtual BaseNode& applyTo( BaseNode& node ) const = 0;

	/**
	 * @return One of the [lexeme type identificators](@ref LexemeType).
	 */
	virtual LexemeType getType() const = 0;

	/**
	 * @brief Returns the updated number of expected matching lexemes.
	 *
	 * If more matching lexemes are expected for this lexeme, the given number is increased
	 * by the number of the lexemes expected. If the lexeme matches a previous lexeme(s)
	 * the number returned is decreased accordingly.
	 *
	 * For example:
	 * "{" lexeme expects closing "}" lexeme. So the first lexeme will increase
	 * the number by 1 and the second one will decrease it by 1.
	 *
	 * @param count - the current number of expected matching lexemes.
	 * @return The updated number of expected matching lexemes.
	 */
	virtual int changeExpectedMatches( int count ) const = 0;

	/**
	 * @brief A null pointer representing no lexeme.
	 */
	static const SharedPointer null;
};


} // parser

#endif // PARSER_PARSER_LEXEME_H

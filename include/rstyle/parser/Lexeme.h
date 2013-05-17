// Lexeme.h

#ifndef RSTYLE_PARSER_LEXEME_H
#define RSTYLE_PARSER_LEXEME_H

#include <rstyle/nodestree/BaseNode.hpp>
#include <memory>



namespace rstyle
{


/**
 * @brief Supported lexemes type identificators
 */
enum class LexemeType
{
	NAME,
	LIST,
	ASSIGN,
	VALUE
};



/**
 * @brief Base interface for all parser lexemes.
 */
class Lexeme
{
public :
	typedef std::shared_ptr< Lexeme > SharedPointer;

public :
	virtual ~Lexeme() = default;

	/**
	 * @brief Parses document for next lexeme.
	 *
	 * @param document - a document that is currently parsed.
	 * @return Next lexeme in parsed document.
	 */
	virtual SharedPointer parseNext( const std::string& document ) const = 0;

	/**
	 * @brief Modifies node according to lexeme semantic (set value, add subnode, etc).
	 *
	 * @param node - node that should be affected by lexeme.
	 * @return Link to node that should be processed by next lexeme.
	 */
	virtual BaseNode& applyTo( BaseNode& node ) const = 0;

	/**
	 * @return one of supported [lexemes type identificator](@ref LexemeType).
	 */
	virtual LexemeType getType() const = 0;

	/**
	 * @brief Changes given number according to lexeme matching semantic.
	 *
	 * @param count - a number that would be changed by method according to lexeme matching semantic.
	 */
	virtual void changeExpectedMatches( int& count ) const = 0;

	/**
	 * @brief Pointer that represents null-lexeme.
	 */
	static const SharedPointer null;
};


} // rstyle

#endif // RSTYLE_PARSER_LEXEME_H

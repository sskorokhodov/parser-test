// Lexeme.h

#ifndef PARSER_PARSER_LEXEME_H
#define PARSER_PARSER_LEXEME_H

#include <memory>

#include <nodestree/BaseNode.hpp>



namespace parser
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
	 * Lexeme matching semantic means that lexeme can be used with zero or more matching lexemes
	 * (have a pair for example).
	 * If matching lexeme(s) should be later in document this method would increase given number according
	 * to number of expected matching lexemes. And if lexeme matches one that has to be before in
	 * document it would decrease given number according to matches that it close.
	 *
	 * For example: "{" lexeme expects closing "}" lexeme. So the first one (opening) lexeme would increase
	 * parameter by 1 and the second one (closing) lexeme would decrease parameter by 1.
	 *
	 * @param count - a number that would be changed by method according to lexeme matching semantic.
	 * @return Number changed by method according to lexeme matching semantic.
	 */
	virtual int changeExpectedMatches( int count ) const = 0;

	/**
	 * @brief Pointer that represents null-lexeme.
	 */
	static const SharedPointer null;
};


} // parser

#endif // PARSER_PARSER_LEXEME_H

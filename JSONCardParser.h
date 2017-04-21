#ifndef JSONCARDPARSER_H
#define JSONCARDPARSER_H

#include <string>
#include <json.hpp>
#include "Card.h"

class JSONCardParser
{
public:
	JSONCardParser();
	Card getCard(std::string cardName);
	void printAllCards() const;
private:
	nlohmann::json allCards;
};
#endif // !JSONCARDPARSER_H

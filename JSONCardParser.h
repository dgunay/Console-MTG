#ifndef JSONCARDPARSER_H
#define JSONCARDPARSER_H

#include <string>
#include "json.hpp"
#include "Card.h"

class JSONCardParser
{
public:
	JSONCardParser();
	void loadCards();
	Card getCard(const std::string& cardName);

	//returns json object for given card name
	nlohmann::json getJson(const std::string& cardName);
	void printAllCards() const;
	bool doneLoading() const;
private:
	nlohmann::json allCards;
	bool finishedLoading;
};
#endif // !JSONCARDPARSER_H

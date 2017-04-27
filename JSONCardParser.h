#ifndef JSONCARDPARSER_H
#define JSONCARDPARSER_H

#include <string>
#include "json.hpp"
#include "Card.h"

/*
	Class for handling loading all MTG card data
	from provided .json file. Also gets
	Card objects deserialized from the .json file.
*/
class JSONCardParser
{
public:
	//Default constructor. 
	JSONCardParser();
	void loadCards();
	Card getCard(const std::string& cardName);

	//Returns json object for given card name
	nlohmann::json getJson(const std::string& cardName);

	//Prints every card. Be careful.
	void printAllCards() const;

	//Returns true if AllCards.json is loaded
	bool doneLoading() const;
private:
	nlohmann::json allCards;
	bool finishedLoading;
};
#endif // !JSONCARDPARSER_H

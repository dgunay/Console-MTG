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
	std::vector<Card> getSimilarCards(const std::string& cardName);

	//Returns json object for a single given card name
	nlohmann::json getJson(const std::string& cardName);

	/*returns json obj with cards matching 70% of characters in
	cardName*/
	nlohmann::json cardsSimilarTo(const std::string& cardName) const;

	//Prints every card. Be careful.
	void printAllCards() const;

	//Returns true if AllCards.json is loaded
	bool doneLoading() const;
private:
	
	nlohmann::json allCards;
	bool finishedLoading;
};
#endif // !JSONCARDPARSER_H

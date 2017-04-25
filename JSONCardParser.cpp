#include "JSONCardParser.h"
#include <iostream>
#include <fstream>

using namespace std;

JSONCardParser::JSONCardParser()
{
	finishedLoading = false;
}

void JSONCardParser::loadCards()
{
	//THIS IS VERY, VERY SLOW (14 seconds)
	ifstream file("AllCards.json");
	file >> allCards;
	finishedLoading = true;
}

Card JSONCardParser::getCard(const string& cardName)
{
	Card card;
	
	nlohmann::json cardData = getJson(cardName);

	if (!cardData.empty())
	{
		card.setName(cardName);
		card.setLayout(cardData.find("layout").value());
		card.setNames(cardData.find("names").value());
		card.setManaCost(cardData.find("manaCost").value());
	}

	return card;
}

nlohmann::json JSONCardParser::getJson(const string& cardName)
{
	nlohmann::json cardData;

	auto iter = allCards.find(cardName);

	if (iter != allCards.end())
	{
		cardData = iter.value();
	}
	else
		cerr << "Card not found." << endl;

	return cardData;
}

void JSONCardParser::printAllCards() const
{
	cout << allCards;
}

bool JSONCardParser::doneLoading() const
{
	return finishedLoading;
}

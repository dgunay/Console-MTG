#include <iostream>
#include <fstream>
#include "JSONCardParser.h"
#include "CardNotFoundException.h"

using namespace std;

JSONCardParser::JSONCardParser()
{
	finishedLoading = false;
}

/*
	Note that this becomes very, very slow if done 
	in Debug mode for Visual Studio.
	Switch to Release mode to speed loading.
*/
void JSONCardParser::loadCards()
{
	ifstream file("AllCards.json");
	file >> allCards;
	finishedLoading = true;
}

Card JSONCardParser::getCard(const string& cardName)
{
	Card card;
	nlohmann::json cardData;

	try
	{
		cardData = getJson(cardName);
	}
	catch (CardNotFoundException c)
	{
		throw c;
	}
		
	if (!cardData.empty())
	{
		card.setName(cardName);
		card.setLayout(cardData.find("layout").value());

		if (cardData.find("names") != cardData.end())
			card.setNames(cardData.find("names").value());

		card.setManaCost(cardData.find("manaCost").value());
		card.setCMC(cardData.find("cmc").value());
		card.setColors(cardData.find("colors").value());

		if (cardData.find("colorIdentity") != cardData.end())
			card.setColorIdentity(cardData.find("colorIdentity").value());

		card.setType(cardData.find("type").value());
		card.setTypes(cardData.find("types").value());

		if (cardData.find("superTypes") != cardData.end())
			card.setSuperTypes(cardData.find("superTypes").value());

		if (cardData.find("subTypes") != cardData.end())
			card.setSubTypes(cardData.find("subTypes").value());

		card.setText(cardData.find("text").value());

		if (cardData.find("hand") != cardData.end())
			card.setHandSizeMod(cardData.find("hand").value());

		if (cardData.find("life") != cardData.end())
			card.setLifeTotalMod(cardData.find("life").value());

		if (cardData.find("power") != cardData.end())
			card.setPower(cardData.find("power").value());

		if (cardData.find("toughness") != cardData.end())
			card.setPower(cardData.find("toughness").value());

		if (cardData.find("loyalty") != cardData.end())
			card.setPower(cardData.find("loyalty").value());
	}

	return card;
}

nlohmann::json JSONCardParser::getJson(const string& cardName)
{
	nlohmann::json cardData;

	auto iter = allCards.find(cardName);

	if (iter != allCards.end())
	{
		cardData = *iter;
	}
	else
		throw CardNotFoundException(cardName);

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
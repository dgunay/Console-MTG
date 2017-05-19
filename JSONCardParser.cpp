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
	nlohmann::json cardData;
	Card card;

	try
	{
		cardData = getJson(cardName);
	}
	catch (CardNotFoundException c)
	{
		throw c;
	}
		
	if (!cardData.empty())
		card = cardData;

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
	{
		cardData = cardsSimilarTo(cardName);

		if (cardData.empty())
			throw CardNotFoundException(cardName);
	}
		

	return cardData;
}

/*
	Finds cards with names that contain at least 70% of 
	the characters of passed string.

	Compare each char in the two strings. Sum the amount of same chars,
	and then convert that to a percentage of characters in the original.

	NEEDS TESTING
*/
nlohmann::json JSONCardParser::cardsSimilarTo(const std::string & cardName) const
{
	nlohmann::json similarCards;
	std::string currentCard;
	double similarity = 0.0;
	double matchedChars = 0.0;

	for (auto card : allCards) //every card in json allCards
	{
		currentCard = card["name"].get<std::string>(); //THIS MIGHT NOT WORK
		similarity = 0.0;
		matchedChars = 0.0;

		int ix = 0;
		for (size_t i = 0; i < cardName.size(); i++) 
		{
			try
			{
				for (char c : cardName)
				{
					if (c == currentCard.at(ix))
						matchedChars += 1.0;

					ix++;
				}
			}
			catch (out_of_range oor)
			{
				break;
			}
		}

		similarity = matchedChars / cardName.size();

		if (similarity >= 0.7)
			similarCards.push_back(card);
	}

	return similarCards;
}

void JSONCardParser::printAllCards() const
{
	cout << allCards;
}

bool JSONCardParser::doneLoading() const
{
	return finishedLoading;
}
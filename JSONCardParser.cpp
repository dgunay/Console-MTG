#include "JSONCardParser.h"
#include <iostream>
#include <fstream>

JSONCardParser::JSONCardParser()
{
	//THIS IS VERY, VERY SLOW (14 seconds)
	std::ifstream file("AllCards.json");
	file >> allCards;
}

Card JSONCardParser::getCard(std::string cardName)
{
	auto iter = allCards.find(cardName);
	Card card;

	//iter.value() is a basic_json. Read documentation
	//what can we get from it?
	if (iter != allCards.end()) 
	{
		//FIGURE OUT HOW TO EXTRACT CARD INFO from the ITER

		//USE THIS SYNTAX TO GRAB INDIVIDUAL FIELDS
		//careful, there are some weird characters in there
		std::cout << iter.key() << " val: " << iter.value().find("type").value();
	}

	std::cout << "card not found" << std::endl;

	return card;
}

void JSONCardParser::printAllCards() const
{
	std::cout << allCards;
}

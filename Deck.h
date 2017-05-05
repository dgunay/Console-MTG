#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"
#include "json.hpp"

class Deck
{
public:
	Deck();

	//return number of cards in deck
	int numberOfCards();

	//puts card on the bottom of the deck
	void insertBottom(Card cd);

	//puts card on the top of the deck
	void insertTop(Card cd);

	//shuffles the cards in the deck randomly
	void shuffle();

	/*
	removes the top card of the deck and returns a
	Card object representing it
	*/
	Card draw();

	nlohmann::json toJSON() const;
private:
	std::vector<Card> cards;
};
#endif // !DECK_H

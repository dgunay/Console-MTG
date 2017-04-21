#include <algorithm>
#include "Deck.h"

Deck::Deck()
{
}

int Deck::numberOfCards()
{
	return cards.size();
}

void Deck::insertBottom(Card cd)
{
	cards.insert(cards.begin(), cd);
}

void Deck::insertTop(Card cd)
{
	cards.push_back(cd);
}

void Deck::shuffle()
{
	random_shuffle(cards.begin(), cards.end());
}

Card Deck::draw()
{
	Card topDeck = cards.back();
	cards.pop_back();
	return topDeck;
}

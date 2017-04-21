#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player
{
public:
	Player();

	vector<Card> getHand() const;
	vector<Card> getGraveyard() const;
	vector<Card> getExilePile() const;

	void playCard(const Card& card);

private:
	int lifePoints;
	vector<Card> deck;
	vector<Card> hand;
	vector<Card> graveyard;
	vector<Card> exilePile;
	vector<Card> playSpace; //consider a new PlaySpace object

};
#endif // !PLAYER_H

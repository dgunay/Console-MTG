#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player
{
public:
	Player();
	Player(int playerNumber);
	std::vector<Card> getHand() const;
	std::vector<Card> getGraveyard() const;
	std::vector<Card> getExilePile() const;

	void playCard(const Card& card);

private:
	int lifePoints;
	int playerNo;
	std::string playerName;
	std::vector<Card> deck;
	std::vector<Card> hand;
	std::vector<Card> graveyard;
	std::vector<Card> exilePile;
	std::vector<Card> playSpace; //consider a new PlaySpace object

};
#endif // !PLAYER_H

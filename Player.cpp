#include "Player.h"

using namespace std;

Player::Player()
{
}

vector<Card> Player::getHand() const
{
	return hand;
}

vector<Card> Player::getGraveyard() const
{
	return graveyard;
}

vector<Card> Player::getExilePile() const
{
	return exilePile;
}

void Player::playCard(const Card & card)
{
	playSpace.push_back(card);
}

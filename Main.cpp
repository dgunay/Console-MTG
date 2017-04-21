/*
Goals of this project:

- create base Card class
	- create subclass Creature, Instant, Sorcery, Enchantment, etc
	- look at MTG json for fields
- create Player class
	- support life points, graveyard, exile pile, board, etc
- scope has been reduced to simply management of the board, I don't have
		the experience to build an actual game logic parser.
- a Deck Builder feature would be awesome
	- load and save locally, build the deck using the JSON Parser
	- Could even make a Gatherer-esque search/filter feature
		- see speed concerns below

- JSON Parser speed is an issue. Loading AllCards.json takes 14s. 
	Solutions:
	- Load it once at startup, forget about it. All access through the parser.
	- Only load the cards used in each deck at the beginning of each game.
	- Multithread the game so that it loads while the user navigates menus.



*/

#include "Card.h"
#include "Land.h"
#include "JSONCardParser.h"


int main()
{
	JSONCardParser test;

	test.getCard("Goblin Electromancer");


	return 0;
}
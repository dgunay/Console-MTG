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

- Game class is WIP
	- Needs proper turn order / phase management
	- Player, Deck, and Card also need more functionality



*/

#include "Card.h"
#include "Land.h"
#include "JSONCardParser.h"
#include "MainMenu.h"

int main()
{
	MainMenu mm;

	mm.initiateMenus();

	return 0;
}
#ifndef GAME_H
#define GAME_H

#include "Player.h"

enum {BEGIN_TURN, UNTAP, UPKEEP, DRAW, FIRST_MAIN, DECLARE_ATTACKS,
	COMBAT_RESOLUTION, SECOND_MAIN, END_STEP};

/*
	Handles a game of Magic.
*/
class Game
{
public:
	Game();
	void runGame();

private:
	int phase;
	std::vector<Player> players;
};
#endif // !GAME_H

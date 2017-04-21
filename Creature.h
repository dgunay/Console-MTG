#ifndef CREATURE_H
#define CREATURE_H

#include "Card.h"

class Creature : public Card
{
public:
	Creature();
	Creature(string name, string type, 
		string subType, vector<string> newManaCost, 
		int power, int toughness);

	int getPower() const;
	int getToughness() const;

	void setPower(int newPower);
	void setToughness(int newToughness);

private:
	int power;
	int toughness;
};
#endif // !CREATURE_H

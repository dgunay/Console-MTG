#ifndef CREATURE_H
#define CREATURE_H

#include "Card.h"

class Creature : public Card
{
public:
	Creature();
	Creature(std::string cardName);

	std::string getPower() const;
	std::string getToughness() const;

	void setPower(std::string newPower);
	void setToughness(std::string newToughness);

private:
	std::string power;
	std::string toughness;
};
#endif // !CREATURE_H

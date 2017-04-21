#ifndef LAND_H
#define LAND_H

#include "Card.h"

class Land : public Card
{
public:
	Land();
	Land(string newName, string newSubType, vector<string> newManaCost);

private:

};
#endif // !LAND_H

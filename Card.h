#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>

using namespace std;

class Card
{
public: 
	Card();
	Card(string newName, string newType, string newSubType,
			vector<string> newManaCost);
	void tap();
	void unTap();
	int convertedManaCost() const;


private:
	string name;
	string type;
	string subType;
	string superType;

	//handles tapping behavior - should maybe do with inheritance instead?
	bool tappable;
	bool tapped;

	//HOW TO HANDLE MULTIPLE COLORS?

	//CMC represented by a vector of "colors"
	vector<string> manaCost;
};
#endif // !CARD_H

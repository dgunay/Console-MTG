#include "Card.h"
#include <iostream>
using namespace std;

Card::Card()
{
}

Card::Card(const string& cardName)
{
	name = cardName;
}

//UNFINISHED, FOR TESTING PURPOSES ONLY
void Card::printCard()
{
	cout << "Name: " << name << endl;
	cout << "Layout: " << layout << endl;

	cout << "Names: ";
	for (string str : names)
		cout << str << ", ";

	cout << "manaCost: ";
	for (string str : manaCost)
		cout << str << ", ";
}

void Card::tap()
{
	tapped = true;
}

void Card::unTap()
{
	tapped = false;
}

void Card::setLayout(const string & newLayout)
{
	layout = newLayout;
}

void Card::setName(const string & newName)
{
	name = newName;
}

void Card::setNames(const vector<string>& newNames)
{
	names = newNames;
}

void Card::setManaCost(const vector<string>& newManaCost)
{
	manaCost = newManaCost;
}

void Card::setCMC(int newCMC)
{
	cmc = newCMC;
}

void Card::setColors(const vector<string>& newColors)
{
	colors = newColors;
}

void Card::setColorIdentity(const vector<string>& newColorIdentity)
{
	colorIdentity = newColorIdentity;
}

void Card::setType(const string & newType)
{
	type = newType;
}

void Card::setTypes(const vector<string>& newTypes)
{
	types = newTypes;
}

void Card::setSuperTypes(const vector<string>& newSuperTypes)
{
	superTypes = newSuperTypes;
}

void Card::setSubTypes(const vector<string>& newSubTypes)
{
	subTypes = newSubTypes;
}

void Card::setText(const string & newText)
{
	text = newText;
}

void Card::setHandSizeMod(int newHandSizeMod)
{
	handSizeModifier = newHandSizeMod;
}

void Card::setLifeTotalMod(int newLifeTotalMod)
{
	startingLifeTotalModifier = newLifeTotalMod;
}

int Card::convertedManaCost() const
{
	return cmc;
}

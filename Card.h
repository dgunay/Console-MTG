#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>
#include "json.hpp"

/*
	DO NOT IMPLEMENT:
	artist, border, flavor, foreignNames, id, mciNumber, 
	multiverseid, number, originalText, originalType, 
	rarity, releaseDate, reserved, timeshifted, variations, watermark

	this data is NOT PROVIDED

	TODO:
	- assignment operator
	- copy constructor
*/
class Card
{
public: 
	Card();
	Card(const std::string& cardName);
	Card(nlohmann::json j);

	void printCard();
	void tap();
	void unTap();

	void setLayout(const std::string& newLayout);
	void setName(const std::string& newName);
	void setNames(const std::vector<std::string>& newNames);
	void setManaCost(const std::string& newManaCost);
	void setCMC(int newCMC);
	void setColors(const std::vector<std::string>& newColors);
	void setColorIdentity(const std::vector<std::string>& newColorIdentity);
	void setType(const std::string& newType);
	void setTypes(const std::vector<std::string>& newTypes);
	void setSuperTypes(const std::vector<std::string>& newSuperTypes);
	void setSubTypes(const std::vector<std::string>& newSubTypes);
	void setText(const std::string& newText);
	void setHandSizeMod(int newHandSizeMod);
	void setLifeTotalMod(int newLifeTotalMod);
	void setPower(std::string newPower);
	void setToughness(std::string newToughness);

	std::vector<std::string> getTypes() const;



	int convertedManaCost() const;


private:
	/*
	Layout (normal, split, flip, double-faced, token, plane,
	scheme, phenomenon, leveler, vanguard, meld.)
	*/
	std::string layout;

	//Name of the card as it appears at the top
	std::string name;

	/*
		Only used for cards with multi faces.
		see http://mtgjson.com/documentation for documentation
	*/
	std::vector<std::string> names;

	/*
		Requires special formatting/paring. 
		See http://mtgjson.com/documentation
	*/
	std::string manaCost;

	//Converted mana cost
	int cmc;

	//card's colors
	std::vector<std::string> colors;

	//mostly used for commander decks
	std::vector<std::string> colorIdentity;

	/*
		Card type as printed on the card.
		MAY CONTAIN STRANGE SYMBOLS
	*/
	std::string type;

	//vector of card's types
	std::vector<std::string> types;

	//vector of card's supertypes
	std::vector<std::string> superTypes;

	//vector of card's subtypes
	std::vector<std::string> subTypes;

	//The text of this card. May contain mana/tap symbols.
	std::string text;

	//Maximum hand size modifier. For Vanguard cards only.
	int handSizeModifier;

	//Starting life total modifier. For Vanguard cards only.
	int startingLifeTotalModifier;

	//Card's power. String type because some cards use *
	std::string power;

	//Card's toughness. String type because some cards use *
	std::string toughness;

	//handles tapping behavior - should maybe do with inheritance instead?
	bool tappable;
	bool tapped;
};
#endif // !CARD_H

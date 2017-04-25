#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>

/*
	DO NOT IMPLEMENT:
	artist, border, flavor, foreignNames, id, mciNumber, 
	multiverseid, number, originalText, originalType, 
	rarity, releaseDate, reserved, timeshifted, variations, watermark

	this data is NOT PROVIDED
*/
class Card
{
public: 
	Card();
	Card(const std::string& cardName);

	void printCard();
	void tap();
	void unTap();

	void setLayout(const std::string& newLayout);
	void setName(const std::string& newName);
	void setNames(const std::vector<std::string>& newNames);
	void setManaCost(const std::vector<std::string>& newManaCost);
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
	std::vector<std::string> manaCost;

	//Converted mana cost
	int cmc;

	//card's colors
	std::vector<std::string> colors;

	//mostly used for commander decks
	std::vector<std::string> colorIdentity;

	//Card type as printed on the card
	std::string type;

	std::vector<std::string> types;
	std::vector<std::string> superTypes;
	std::vector<std::string> subTypes;

	//The text of this card. May contain mana/tap symbols.
	std::string text;

	//Maximum hand size modifier. For Vanguard cards only.
	int handSizeModifier;

	//Starting life total modifier. For Vanguard cards only.
	int startingLifeTotalModifier;



	//handles tapping behavior - should maybe do with inheritance instead?
	bool tappable;
	bool tapped;
};
#endif // !CARD_H

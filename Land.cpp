#include "Land.h"

Land::Land()
{
}

//theManaCost thing is useless for a land
Land::Land(string newName, string newSubType, vector<string> newManaCost)
	: Card(newName, "Land", newSubType, newManaCost)
{

}

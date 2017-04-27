#ifndef CARDNOTFOUNDEXCEPTION_H
#define CARDNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>

/*
	Custom exception for queries to a JSONCardParser
	that do not match a card.
*/
class CardNotFoundException : public std::exception
{
public:
	CardNotFoundException()
	{
		msg = "Card";
	}

	CardNotFoundException(std::string cardName)
	{
		if (!cardName.empty())
			msg += "Card '" + cardName + "' ";
		else 
			msg += "Card ";

		msg += "not found.";
	}

	const char* what() const throw()
	{
		return msg.c_str();
	}

private:
	std::string msg;
};

#endif
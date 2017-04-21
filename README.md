+++++++++++++++++
++ CONSOLE MTG ++
+++++++++++++++++

A console-based Magic: The Gathering play environment and deck builder. Like Cockatrice but way, way less nice to look at. Heavily WIP. 

By:
Devin Gunay
devingunay@gmail.com


ABOUT:

This is a little pet project of mine. It started out as an exercise in polymorphism (as my past projects did as well), but then 
I thought about just how I would go about implementing a decent variety of the thousands of Magic cards that are out there. 

I had thought about doing it two ways:

1. Implementing only a small cube of cards to pick from, and hard-coding their behaviors/interactions.

    Which is doable, but probably very tedious.
    
2. Accessing cards through some kind of API or data format, and then writing a rules text parser that could interpret the behavior of 
any Magic card and control the flow of the game according to the rules of Magic.

	That's really, really cool sounding but frickin' hard and probably way above my level at the moment. However, the bit about accessing 
	all published MTG cards, I figured I could do. So I toned down the scope of my project and left rules handling to the users.

This program was my first exposure to JSON and my first usage of a library that wasn't the STL or cstdlib. So yay, milestones.

The card data is provided by AllCards.json, compiled by https://mtgjson.com/

The program handles .json files in C++ using the JSON for Modern C++ library (https://github.com/nlohmann/json)

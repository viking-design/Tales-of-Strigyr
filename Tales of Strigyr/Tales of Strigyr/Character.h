#pragma once
#include "Item.h"
#include "Weapon.h"
#include <iostream>
#include <string>

// Declaring Character class
class Character {
protected:
	// Class attributes
	int stats[5];
	int health;
	int race;
	int role;
	std::string name;
public:
	// This method gets the character's role, this is useful for adding class bonuses or for class specific interactions
	int getRole();

	// This method gets the character's race, this will be useful for race bonuses and unique interactions
	int getRace();

	// This method allows the character's name to be printed in dialogue
	std::string getName();

	// This method gets a character's stats
	int getStats(int num);

	// This method will return the value of the D20 roll
	int d20(int target, int stat);
};


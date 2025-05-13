// This is the header file for the Player class
#pragma once
#include "Character.h"

// Declaring Player class
class Player : public Character {
private:
	// Class attributes
	bool hasMagic;
	bool talkToAnimals;
public:
	// Constructors and Destructor
	Player();

	Player(int newHealth, int newRace, int newRole, std::string newName, bool newMagic, bool newAnimal);

	~Player();

	// This method allows the player to set their name
	void setName();

	// This method allows the player to select their character's race
	void setRace();

	// This method allows the player to select their character's role
	void setRole();

	// This method allows the player to spend their points on their character's stats
	void setStats();

	// This method resets all of the player object's stats
	void reset();

	// This method will change a stat's value
	void changeStat(int statNum, int newStat);

	// This method gets the value for talkToAnimals
	bool getAnimal();
};
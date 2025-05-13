#include "Character.h"

// This method gets the character's role, this is useful for adding class bonuses or for class specific interactions
int Character::getRole() {
	/*
	1 - Adventurer
	2 - Knight
	3 - Archer
	4 - Mage
	5 - Cleric
	6 - Barbarian
	7 - Bard
	8 - Rogue
	*/
	return role;
}

// This method gets the character's race, this will be useful for race bonuses and unique interactions
int Character::getRace() {
	/*
	1 - Human
	2 - Dwarf
	3 - Elf
	4 - Goblin
	5 - Half-Orc
	*/
	return race;
}

// This method allows the character's name to be printed in dialogue
std::string Character::getName() {
	return name;
}
// This method gets a character's stats
int Character::getStats(int num) {
	/*
	KEY:
	0 = STRENGTH
	1 = AGILITY
	2 = CONSTITUTION
	3 = CHARISMA
	4 = KNOWLEDGE
	*/
	return stats[num];
}

// This function will return the D20 value
int Character::d20(int target, int stat) {
	// Rolls the D20
	int roll = rand() % 21;

	// Decides how much is added to or taken away from the roll based on stats
	if ((stat >= -20) && (stat < -15)) {
		roll -= 6;
	}
	else if ((stat >= -15) && (stat < -10)) {
		roll -= 4;
	}
	else if ((stat <= -5) && (stat > -10)) {
		roll -= 2;
	}
	else if ((stat <= 5) && (stat > -5)) {
		roll += 0;
	}
	else if ((stat <= 10) && (stat > 5)) {
		roll += 2;
	}
	else if ((stat <= 15) && (stat > 10)) {
		roll += 4;
	}
	else if ((stat <= 20) && (stat > 15)) {
		roll += 6;
	}

	// Looks at the character's race and decides whether a reroll will be permitted
	bool reroll = false;
	if ((race == 2) && (stat == 0)) { // Dwarf strength reroll
		reroll = true;
	}
	else if ((race == 3) && (stat == 4)) { // Elf knowledge reroll
		reroll = true;
	}
	else { // Every race with no rerolls or no reroll can be applied
		reroll = false;
	}

	// Determines if the charisma race pentalty needs to be applied to the roll
	if (race == 4 || race == 5) {
		if (race == 4 && (stat == 3)) { // Goblin Penalty
			roll -= 3;
		}
		else if (race == 5 && (stat == 3)) { // Half-Orc Penalty
			roll -= 6;
		}
	}


	// Determines whether the roll passed or failed
	if (roll >= target) { // Passes the skill check
		std::cout << "You have rolled a " << roll << std::endl;
		return roll;
	}
	else if ((roll < target) && (reroll == true)) { // Fails the skill check but can reroll

		// Text to let the player know that they have failed the roll, but are currently using the reroll
		std::cout << "You have failed the skill check, but you are able to reroll" << std::endl;

		// Rerolls the D20
		roll = rand() % 21;

		// Decides how much is added to or taken away from the roll based on stats
		if ((stat >= -20) && (stat < -15)) {
			roll -= 6;
		}
		else if ((stat >= -15) && (stat < -10)) {
			roll -= 4;
		}
		else if ((stat <= -5) && (stat > -10)) {
			roll -= 2;
		}
		else if ((stat <= 5) && (stat > -5)) {
			roll += 0;
		}
		else if ((stat <= 10) && (stat > 5)) {
			roll += 2;
		}
		else if ((stat <= 15) && (stat > 10)) {
			roll += 4;
		}
		else if ((stat <= 20) && (stat > 15)) {
			roll += 6;
		}

		// Displays the message and returns the value that was rolled
		std::cout << "You have rolled a " << roll << std::endl;
		return roll;
	}
	else { // Returns the value of the roll
		std::cout << "You have rolled a " << roll << std::endl;
		return roll;
	}
}
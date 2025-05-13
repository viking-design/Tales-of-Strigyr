#pragma once
#include "Character.h"
class Npc : public Character {
protected:
	// Class attributes
	int targetID;
	bool healer;

	// This method chooses who to target in combat
	void chooseTarget(int targets[]);

	// This method selects the target
	void selectTarget(int selectedTarget);
public:
	// This method gets the healer variable
	bool getHealer();
};


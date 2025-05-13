#include "Npc.h"

// This method chooses who to target in combat
void Npc::chooseTarget(int targets[]) {

}

// This method selects the target
void Npc::selectTarget(int selectedTarget) {
	targetID = selectedTarget;
}

// This method gets the healer variable
bool Npc::getHealer() {
	return healer;
}

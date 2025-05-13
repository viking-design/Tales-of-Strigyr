
// C++ standard libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Header files
#include "Player.h"
#include "Character.h"
#include "Trader.h"
#include "Item.h"
#include "Weapon.h"
#include "Npc.h"
#include "Settlement.h"
#include "Location.h"


int main() {
	// Ensures that all randomly generated numbers are truly random as the program runs
	srand(time(0));

	// Declaring variables for the main menu/game
	int choice = 0;
	bool userInputs = true;
	bool hasCharacter = false;

	// Pointers for optimisation
	bool* userInputsPTR = &userInputs;

	// Prototype functions
	void statTut();
	void menuTut();
	void itemTut();
	void npcTut();
	void combatTut();

	// Declaring player object
	Player* mainPlayer = new Player();

	// Main Menu
	while (userInputs) {
		// Text that shows the user all the menu options
		cout << "Welcome to Tales of Strigyr!" << endl;
		cout << "Enter the number of which option you would like to select" << endl;
		cout << "1 - Start a new game\n2 - Continue a save game [THIS IS FOR A FUTURE BUILD, THIS HAS NO FUNCTION]\n3 - Access the tutorial\n4 - Access the character creator\n5 - Read patch notes\n6 - Exit the program" << endl << endl << "Enter your input: ";
		// Taking user input and validates it
		while (!(cin >> choice) || (choice <= 0 || choice >= 7)) {
			system("cls");
			cout << "ERROR: INPUT NOT VALID!" << endl << "ENTER A NEW INPUT" << endl;
			cout << "Welcome to Tales of Strigyr!" << endl;
			cout << "Enter the number of which option you would like to select" << endl;
			cout << "1 - Start a new game\n2 - Continue a save game [THIS IS FOR A FUTURE BUILD, THIS HAS NO FUNCTION]\n3 - Access the tutorial\n4 - Access the character creator\n5 - Read patch notes\n6 - Exit the program" << endl << endl << "Enter your input: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		// This handles the user's input
		switch (choice) {
		case 1: // New game
			system("cls");
			if (hasCharacter) { // If the user has already created a character, they will be given the option to reuse them
				cout << "You have already made a character using the character creator" << endl;
				cout << "Would you like to use ";
				mainPlayer->getName();
				cout << "?" << endl << endl << "1 - Yes\n2 - No" << endl;
				while (!(cin >> choice) || (choice <= 0 || choice >= 3)) {
					system("cls");
					cout << "ERROR: INPUT NOT VALID!" << endl << "ENTER A NEW INPUT" << endl;
					cout << "You have already made a character using the character creator" << endl;
					cout << "Would you like to use ";
					mainPlayer->getName();
					cout << "?" << endl << endl << "1 - Yes\n2 - No" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				switch (choice) {
				case 1: // Use character that was already made
					break;
				case 2: // Create a new character
					system("cls");
					mainPlayer->reset();
					mainPlayer->setName();
					mainPlayer->setRace();
					mainPlayer->setRole();
					mainPlayer->setStats();
					break;
				}
			}
			else { // This lets the user create a character if they haven't already created a character
				system("cls");
				mainPlayer->reset();
				mainPlayer->setName();
				mainPlayer->setRace();
				mainPlayer->setRole();
				mainPlayer->setStats();
				break;
			}
			break;
		case 2: // Continue Save game
			cout << "This feature is not implemented yet, this is simply a placeholder for a future version of the game that will contain a savegame feature" << endl;
			break;
		case 3: // Tutorial
			system("cls");
			cout << "Welcome to Tales of Strigyr's tutorial\n\n1. Reading character stats\n2. Navigating menus\n3. Item management\n4. How to manage NPC relations\n5. How to engage in combat\n\nEnter the number of the tutorial you wish to interact with" << endl;
			while (!(cin >> choice) || (choice <= 0 || choice >= 6)) {
				cout << "ERROR: INPUT NOT VALID\nENTER A NEW INPUT" << endl;
				cout << "Welcome to Tales of Strigyr's tutorial\n\n1. Reading character stats\n2. Navigating menus\n3. Item management\n4. How to manage NPC relations\n5. How to engage in combat\n\nEnter the number of the tutorial you wish to interact with" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			switch (choice) {
			case 1: // Reading character stats
				statTut();
				break;
			case 2: // Navigating menus
				menuTut();
				break;
			case 3: // Item management
				itemTut();
				break;
			case 4: // How to manage NPC relations
				npcTut();
				break;
			case 5: // How to engage in combat
				combatTut();
				break;
			}
			break;
		case 4: // Access the character creator
			system("cls");
			mainPlayer->reset();
			mainPlayer->setName();
			mainPlayer->setRace();
			mainPlayer->setRole();
			mainPlayer->setStats();
			hasCharacter = true;
			system("cls");
			break;
		case 5: // Patch notes
			cout << "Tales of Strigyr Version 1.0.0 Patch Notes:\n\n* No changes made since this is the first version of this game release" << endl;
			break;
		case 6: // Quit program
			userInputs = false;
			break;
		}
	}

	return 0;
}

// This function contains the stats tutorial
void statTut() {
	system("cls");
	char progress;
	Player* tutorial = new Player(0, 1, 1, "", false, false);

	cout << "Welcome to the stats tutorial!\n\nIn this tutorial, you will learn what all the stats mean and how different stats can influence your gameplay experience" << endl;

	// ================ STRENGTH TUTORIAL ================

	cout << "The first stat to look at is strength. Strength adds to your strength rolls (rolls that use your strength stats) and may influence your combat rolls (you will see an example of this in the combat tutorial)" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");

	cout << "Here is an example of a strength roll" << endl << endl;
	cout << "A tree falls and blocks your path. Roll 14+ to remove it" << endl;
	cout << "Enter 1 and hit enter to continue with the roll" << endl;
	cin >> progress;

	// Skill check
	if (tutorial->d20(14, 0)) { // Passes the skill check
		cout << "You managed to move the tree out of the way" << endl;
	}
	else { // Fails the skill check
		cout << "You were unable to move the tree" << endl;
	}

	// Waits for player input before showing how stats can positively influence stat rolls
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");
	cout << "Here is another example of a strength roll but you will be given the strength stat of 10" << endl << endl;
	tutorial->changeStat(0, 10);
	cout << "You attempt to lift up the crate. Roll 16+ to pick it up" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;

	// Skill check
	if (tutorial->d20(16, 0)) { // Passes the skill check
		cout << "You have successfully picked up the crate" << endl;
	}
	else { // Fails the skill check
		cout << "You tried to pick up the crate... And broke it" << endl;
	}

	// Waits for player input before showing how stats can negatively influence stat rolls
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");
	cout << "Here is an example of how having a negative stat can impact on stat rolls" << endl;
	tutorial->changeStat(0, -10);
	cout << "For the purposes of this tutorial, you have been given the strength stat of -10" << endl << endl;
	cout << "You have been challenged to an arm wrestling competition, roll 12+ to win" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	if (tutorial->d20(12, 0)) { // Passes the skill check
		cout << "You have won the arm wrestling competition" << endl;
	}
	else { // Fails the skill check
		cout << "You lost the arm wrestling competition" << endl;
	}

	// Waits for the player to enter a key before moving on to showing how rerolls work
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");
	delete tutorial;
	Player* tutorial2 = new Player(0, 2, 1, "", false, false);
	tutorial2->changeStat(0, -20);
	cout << "Some races will get the ability to reroll failed rolls once.\nThe type of roll depends on the race, for example, dwarves can reroll failed strength rolls and elves can reroll failed knowledge rolls" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");
	cout << "For the purposes of this example, you have been given the strength stat of -20" << endl;
	cout << "Here is an example of how a reroll would work:" << endl;
	cout << endl << "You attempt to move the stone in front of you, roll 14+ to move the stone" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;

	// Skill check
	if (tutorial2->d20(14, 0)) { // Passes the skill check
		cout << "You have successfully moved the stone out of the way" << endl;
	}
	else { // Fails the skill check
		cout << "You tried to move the stone... And stand there in embarassment in front of your party" << endl;
	}

	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	delete tutorial2;
	system("cls");
	cout << "This is everything you need to know about the strength stat\nThe next stat you will learn about is agility" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");

	// ================ AGILITY TUTORIAL ================

	cout << "Agility refers to how quick your character is on their feet, being able to dodge enemy attacks (again, you will see an example of this in the combat tutorial) and contributes to agility rolls just like how strength does\n" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");
	Player* agility = new Player(0, 1, 0, "", false, false);
	cout << "Here is an example of an agility roll" << endl;
	cout << "You have decided to scale the fence blocking your path, roll a 10+ to successfully scale it" << endl;

	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;

	// Skill check
	if (agility->d20(10, 1)) { // Passes the skill check
		cout << "You have successfully scaled the fence" << endl;
	}
	else { // Fails the skill check
		cout << "You tried to scale the fence... And and fall down, receiving 1 damage as a result of the fall" << endl;
	}
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");

	cout << "That concludes everything you need to know about the agility stat\nThe next stat you will learn about is constitution" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");

	// ================ CONSTITUTION TUTORIAL ================

	cout << "The constitution stat refers to how healthy and active your character is" << endl;
	cout << "Constitution does not have any impact on rolls, but has an impact on how much bonus health your character will receive" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");

	cout << "That concludes the constitution tutorial\nThe next stat you will learn about is charisma" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");

	// ================ CHARISMA TUTORIAL ================

	cout << "Charisma refers to how well your character is able to speak to others and negotiate and has an impact on charisma rolls" << endl;
	cout << "This could result in better deals for your character when bartering with merchants or being able to persuade a guard into letting you into an area you're not supposed to be" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");
	cout << "Here is an example of a charisma roll" << endl;
	cout << "You wake up to a holding cell and you see a fellow inmate, you decide to talk to the inmate, roll 8+ to talk to him" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;

	// Skill check
	if (agility->d20(10, 1)) { // Passes the skill check
		cout << "The inmate tells that you were put in the cell for being a public nuisance according to one of the guards" << endl;
	}
	else { // Fails the skill check
		cout << "You try to talk to the inmate, but he doesn't want to say anything" << endl;
	}
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");
	delete agility;
	cout << "That concludes everything you need to know about the charisma stat\nThe next and last stat you will learn about is knowledge" << endl;

	// ================ KNOWLEDGE TUTORIAL ================

	Player* knowledge = new Player(0, 3, 0, "", true, true);
	cout << "Knowledge refers to your character's education and has an impact on casting spells. This stat also has an impact on knowledge rolls" << endl;
	cout << "High knowledge characters will know key context to specific events and locations" << endl;
	cout << "For example, if your character entered a crypt and saw a tomb with golden engravings, your character will know that this was the tomb of an ancient king" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");

	cout << "Knowledge affects the complexity of the spells your character can cast" << endl;
	cout << "For example, with a low knowledge stat, your character will be able to cast spells such as fireball and lightning strike" << endl;
	cout << "But would not be able to cast a complex spell such as invisibility and resurrection (spell casting will be elaborated on in the combat tutorial) " << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");

	cout << "Here is an example of how knowledge would affect your characters knowledge around certain events" << endl;
	cout << "For the purposes of this example, you will be given the knowledge stat of 0" << endl;

	// Knowledge check
	for (int i = 0; i < 2; i++) {
		if (i == 1) { // Changes the knowledge stat after the first iteration
			knowledge->changeStat(4, 10);
			cout << "You have been granted the knowledge stat of 10 to see what new knowledge you will learn about the town" << endl;
		}
		if (knowledge->getStats(4) >= 10) {
			cout << "You enter Newport, a town founded to act as the new centre of trade for the kingdom" << endl;
			cout << "Enter 1 and hit enter to continue" << endl;
			cin >> progress;
			system("cls");
		}
		else {
			cout << "You have entered Newport" << endl;
			cout << "Enter 1 and hit enter to continue" << endl;
			cin >> progress;
			system("cls");
		}
	}
	delete knowledge;
	cout << "And that is everything you need to know about the knowledge stat and this concludes the stats tutorial." << endl;
	cout << "Thank you for taking the time to complete this tutorial!" << endl;
	cout << "Enter 1 and hit enter to continue" << endl;
	cin >> progress;
	system("cls");
}

// This function contains the menu tutorial
void menuTut() {
	system("cls");

}

// This function contins the item tutorial
void itemTut() {
	system("cls");

}

// This function contains the NPC relations tutorial
void npcTut() {
	system("cls");

}

// This function contains the combat tutorial
void combatTut() {
	system("cls");
	/*
	Notes for combat tutorial:
	Show an example of bonus strength adding to damage
	Show an example of bonus agility making it easier to dodge attacks
	Show an example of how knowledge works with spell casting
	*/
}
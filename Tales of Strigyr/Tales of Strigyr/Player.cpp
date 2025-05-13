// This is the implementation file for the Player class
#include "Player.h"

// Constructors
Player::Player() {
	stats[0] = 0; // Strength initialisation
	stats[1] = 0; // Agility initialisation
	stats[2] = 0; // Constitution initialisation
	stats[3] = 0; // Charisma initialisation
	stats[4] = 0; // Knowledge initialisation
	health = 0;
	race = 0;
	role = 0;
	name = "";
	hasMagic = false;
	talkToAnimals = false;
}

Player::Player(int newHealth, int newRace, int newRole, std::string newName, bool newMagic, bool newAnimal) {
	stats[0] = 0; // Strength initialisation
	stats[1] = 0; // Agility initialisation
	stats[2] = 0; // Constitution initialisation
	stats[3] = 0; // Charisma initialisation
	stats[4] = 0; // Knowledge initialisation
	health = newHealth;
	race = newRace;
	role = newRole;
	name = newName;
	hasMagic = newMagic;
	talkToAnimals = newAnimal;
}

// Destructor
Player::~Player() {

}


// This method allows the player to set their name
void Player::setName() {
	std::cout << "What is your character's name?" << std::endl;
	std::cin.ignore();
	getline(std::cin, name);
	std::cout << std::endl;
}

// This method allows the player to select their character's race
void Player::setRace() {
	// This runs through all the text stored for character creation and makes future changes easier
	const int MAX_RACE = 5;

	// This array has all the race names
	std::string raceNames[MAX_RACE] = { "Human", "Dwarf", "Elf", "Goblin", "Half-Orc" }; //These are the names of each race

	// This array has all the descriptions of each race
	std::string raceDesc[MAX_RACE] = { "Humans are numerous throughout the lands and can be found almost everywhere, they are adaptable to almost anything, as seen through some of their settlements. \n(+1 to all stats)", "Dwarves are durable and strong, however, other races tend to mock them for their short stature. \n(+3 strength, -3 agility, +5 constitution, -2 charisma and the ability to reroll failed strength rolls once per action)", "Elves are nimble, charismatic and intelligent but they are less durable than other races. \n(+4 agility, -3 constitution, +4 charisma, the ability to reroll failed knowledge rolls once and the ability to speak to some animals)", "Goblins are small, agile and cunning, but are physically weak and unable to withstand a lot of damage. \n(-4 to strength, +6 agility, -4 constitution and Goblins possess the ability to speak to other Goblins, but suffers from -3 charisma when talking to non-Goblins)", "Orcs are typically violent and territorial, but strong and durable. Half-Orcs don't possess the aggression of Orcs, but possess some of their strength and durability at the expense of losing the attributes of their parent race. \n(+4 to strength, +4 to constitution, -4 agility, and has the ability to talk to Orcs but has -6 charisma when talking to non-Orcs)\n" };

	// This shows the player what races are available for them to play as what what their attributes are
	std::cout << "Choose " << name << "'s race from the selection below:" << std::endl << std::endl;
	int numPlacement = 1;
	for (int i = 0; i < MAX_RACE; i++) {
		std::cout << numPlacement << ". " << raceNames[i] << " - " << raceDesc[i] << std::endl << std::endl;
		numPlacement++;
	}
	numPlacement = 1;
	std::cout << "Select the race you wish " << name << " to be" << std::endl;

	// This recieves the user's input and validates it
	while (!(std::cin >> race) || (race <= 0 || race >= MAX_RACE + 1)) {
		std::cout << "Invalid input!" << std::endl << "Try again!" << std::endl << std::endl << std::endl << std::endl;
		for (int i = 0; i < MAX_RACE; i++) {
			std::cout << numPlacement << ". " << raceNames[i] << " - " << raceDesc[i] << std::endl << std::endl;
			numPlacement++;
		}
		numPlacement = 1;
		std::cout << "Select the race you wish " << name << " to be" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// This method allows the player to select their character's role
void Player::setRole() {
	// This runs through all the text stored for character creation and makes future changes easier to manage
	const int MAX_ROLE = 7;

	// This array has all the class names
	std::string classNames[MAX_ROLE] = { "Adventurer", "Knight", "Archer", "Mage", "Cleric", "Barbarian", "Bard" };

	// This array has all the class descriptions
	std::string classDesc[MAX_ROLE] = { "Adventurers are people who go to distant lands and seek a life full of adventure, believing that they might find a hidden treasure whilst on their travels.\n(Has no special bonuses but has no drawbacks either)", "Knights are noble warriors that serve their liege and maintain law and order throughout their liege's lands.\n(+4 strength, -3 agility, +5 constitution, and has access to special moves)", "Archers, similar to knights, serve their liege in their army during times of war and take up an auxillary role in battles. During times of peace, they are usually found on garrison duty.\n(+4 agility, -4 constitution and has access to special moves)", "Mages are magic wielders who have the ability to perform acts that are seen as unnatural or impossible to achieve under normal circumstances.\n(-2 strength, +2 knowledge, has access to special moves and access to mana)", "Clerics, just like mages, are magic wielders however, they dedicate their magic to helping others.\n(-3 strength, +2 charisma, +2 knowledge, has access to special moves and access to mana)", "Barbarians are typically seen as wild savages with their fury unmatched in combat but as a result most people refuse to negotiate with barbarians.\n(+3 strength, -2 agility, +3 constitution, -4 charisma, -3 knowledge, has access to special moves and some characters may outright refuse any attempt of interaction)", "Bards are charismatic travellers, charming friends and foes alike with their music.\n(-3 strength, +2 agility, -3 constitution, +4 charisma and has access to special moves)" };

	// This shows the player what classes are available for them to play as what what their attributes are
	std::cout << "Choose " << name << "'s class from the selection below:" << std::endl << std::endl;
	int numPlacement = 1;
	for (int i = 0; i < MAX_ROLE; i++) {
		std::cout << numPlacement << ". " << classNames[i] << " - " << classDesc[i] << std::endl << std::endl;
		numPlacement++;
	}
	numPlacement = 1;

	// This receives and validates the user's input
	std::cout << "Select the class you wish " << name << " to be" << std::endl;
	while (!(std::cin >> role) || (role <= 0 || role >= MAX_ROLE + 1)) {
		std::cout << "Invalid input!" << std::endl << "Try again!" << std::endl << std::endl << std::endl << std::endl;
		for (int i = 0; i < MAX_ROLE; i++) {
			std::cout << numPlacement << ". " << classNames[i] << " - " << classDesc[i] << std::endl << std::endl;
			numPlacement++;
		}
		numPlacement = 1;
		std::cout << "Select the class you wish " << name << " to be" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// This method allows the player to spend their points on their character's stats
void Player::setStats() {
	// This array has the names of all the stats
	std::string statNames[5] = { "Strength", "Agility", "Constitution", "Charisma", "Knowledge" }; //These are basic stats

	// This array has all the descriptions of each stat
	std::string statDesc[5] = { "This represents how strong your character is. It increases your strength rolls and increases damage for some attacks", "This represents how agile and nimble your character is. It increases your dodge rolls, your stealth rolls (if applicable) and may allow for unique entrances", "This represents how physically active your character is. It increases how much additional hp your character gets", "This represents how charismatic your character is. It increases your charisma rolls and allows you to increase relations with characters easier", "This represents your character's knowledge. It increases your character's knowledge rolls, increases your mana regeneration per turn and may reveal useful information either about certain enemies or events" };

	// This will look at the race the character selected and apply the bonuses as listed in the character creation
	switch (race) {
	case 1: // Human
		for (int i = 0; i < 5; i++) {
			stats[i] += 1;
		}
		break;
	case 2: // Dwarf
		stats[0] += 3; // Strength
		stats[1] -= 3; // Agility
		stats[2] += 5; // Constitution
		stats[3] -= 2; // Charisma
		break;
	case 3: // Elf
		stats[1] += 4; // Agility
		stats[2] -= 3; // Constitution
		stats[3] += 4; // Charisma
		break;
	case 4: // Goblin
		stats[0] -= 4; // Strength
		stats[1] += 6; // Agility
		stats[2] -= 4; // Constitution
		break;
	case 5: // Half-Orc
		stats[0] += 4; // Strength
		stats[1] -= 4; // Agility
		stats[2] += 4; // Constitution
		break;
	}

	// This will look at the race the character selected and apply the bonuses as listed in the character creation
	switch (role) {
	case 1: // Adventurer
		break;
	case 2: // Knight
		stats[0] += 3; // Strength
		stats[1] -= 3; // Agility
		stats[2] += 5; // Constitution
		stats[3] -= 2; // Charisma
		break;
	case 3: // Archer
		stats[1] += 4; // Agility
		stats[2] -= 3; // Constitution
		stats[3] += 4; // Charisma
		break;
	case 4: // Mage
		stats[0] -= 4; // Strength
		stats[1] += 6; // Agility
		stats[2] -= 4; // Constitution
		hasMagic = true;
		break;
	case 5: // Cleric
		stats[0] += 4; // Strength
		stats[1] -= 4; // Agility
		stats[2] += 4; // Constitution
		hasMagic = true; // Enables magic
		break;
	case 6: // Barbarian
		stats[0] += 3; // Strength
		stats[1] -= 2; // Agility
		stats[2] += 3; // Constitution
		stats[3] -= 3; // Charisma
		stats[4] -= 3; // Knowledge
		break;
	case 7: // Bard
		stats[0] -= 3; // Strength
		stats[1] += 2; // Agility
		stats[2] -= 3; // Constitution
		stats[3] += 4; // Charisma
		break;
	case 8: // Rogue

		break;
	}

	// This array will hold the lowest value that each stat can be for the player
	int tempStats[5] = { 0, 0, 0, 0, 0 };

	// This for loop will copy over the lowest values in the main stats array
	for (int i = 0; i < 5; i++) {
		tempStats[i] = stats[i];
	}

	// This allows the user to input how many points they would like to put into each stat to a maximum of 20 per stat
	int points = 25;
	const int MAX_STAT = 21;
	const int LOW_STAT = -21;
	int option = 0;
	bool hasPoints = true;
	bool pointConfirm = true;
	int placement = 1;
	int temp1 = 0;
	int temp2 = 0;

	// This allows the player to invest their points into their character's stats
	while (hasPoints) {
		system("cls");

		// This shows user their character's stats
		std::cout << "These are " << name << "'s current stats:" << std::endl;
		for (int j = 0; j < 5; j++) {
			std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
			placement++;
		}
		placement = 1;

		// This informs the user how much points they have left to spend on their character's stats
		switch (points) {
		case 1:
			std::cout << "You have " << points << " point left to spend" << std::endl;
			break;

		default:
			std::cout << "You have " << points << " points left to spend" << std::endl;
		}


		// This receives and validates user input
		std::cout << "Enter the number of the stat you would like to spend your points on" << std::endl;
		while (!(std::cin >> option) || (option <= 0 || option >= 6)) {
			system("cls");
			std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
			std::cout << "These are " << name << "'s current stats:" << std::endl;
			for (int j = 0; j < 5; j++) {
				std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
				placement++;
			}
			placement = 1;
			switch (points) {
			case 1:
				std::cout << "You have " << points << " point left to spend" << std::endl;
				break;

			default:
				std::cout << "You have " << points << " points left to spend" << std::endl;
			}
			std::cout << "Enter the number of the stat you would like to spend your points on" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// This decides what stat is going to be changed
		switch (option) {
		case 1: // Strength
			while (pointConfirm) {
				// Receives and validates user input
				std::cout << "How many points would you like to enter for Strength?" << std::endl;
				while (!(std::cin >> option) || (option <= LOW_STAT || option >= MAX_STAT)) {
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					std::cout << "How many points would you like to enter for Strength?" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				// Further input validation
				temp1 = option + stats[0];
				temp2 = points - option;
				if (option == 0) { // Allows the player to add 0 points to a stat/leave the stat without changing it
					pointConfirm = false;
				}
				else if (temp1 <= tempStats[0] - 1) { // This makes sure that the player doesn't go below their race/role stats
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (temp1 > MAX_STAT - 1) { // This stops a weird edge case where specific stats can go above 20
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (option < 0 && (temp1 > tempStats[0] && temp1 < stats[0])) { // Allows the user to take away points
					stats[0] += option;
					points -= option;
					pointConfirm = false;
				}
				else if (temp2 < 0) { // This stops the player from investing more points than they currently have
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (points == 0) { // This stops the user from investing more points if they have 0
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else { // This allows the user to actually invest their points
					stats[0] += option;
					points -= option;
					pointConfirm = false;
				}
			}
			pointConfirm = true;
			break;

		case 2: // Agility
			while (pointConfirm) {
				// Receives and validates user input
				std::cout << "How many points would you like to enter for Agility?" << std::endl;
				while (!(std::cin >> option) || (option <= LOW_STAT || option >= MAX_STAT)) {
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					std::cout << "How many points would you like to enter for Agility?" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				// Further input validation
				temp1 = option + stats[1];
				temp2 = points - option;
				if (option == 0) { // Allows the player to add 0 points to a stat/leave the stat without changing it
					pointConfirm = false;
				}
				else if (temp1 <= tempStats[1] - 1) { // This makes sure that the player doesn't go below their race/role stats
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (temp1 > MAX_STAT - 1) { // This stops a weird edge case where specific stats can go above 20
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (option < 0 && (temp1 > tempStats[1] && temp1 < stats[1])) { // Allows the user to take away points
					stats[1] += option;
					points -= option;
					pointConfirm = false;
				}
				else if (temp2 < 0) { // This stops the player from investing more points than they currently have
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (points == 0) { // This stops the user from investing more points if they have 0
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else { // This allows the user to actually invest their points
					stats[1] += option;
					points -= option;
					pointConfirm = false;
				}
			}
			pointConfirm = true;
			break;

		case 3: // Constitution
			while (pointConfirm) {
				// Receives and validates user input
				std::cout << "How many points would you like to enter for Constitution?" << std::endl;
				while (!(std::cin >> option) || (option <= LOW_STAT || option >= MAX_STAT)) {
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					std::cout << "How many points would you like to enter for Constitution?" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				// Further input validation
				temp1 = option + stats[2];
				temp2 = points - option;
				if (option == 0) { // Allows the player to add 0 points to a stat/leave the stat without changing it
					pointConfirm = false;
				}
				else if (temp1 <= tempStats[2] - 1) { // This makes sure that the player doesn't go below their race/role stats
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (temp1 > MAX_STAT - 1) { // This stops a weird edge case where specific stats can go above 20
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (option < 0 && (temp1 > tempStats[2] && temp1 < stats[2])) { // Allows the user to take away points
					stats[2] += option;
					points -= option;
					pointConfirm = false;
				}
				else if (temp2 < 0) { // This stops the player from investing more points than they currently have
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (points == 0) { // This stops the user from investing more points if they have 0
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else { // This allows the user to actually invest their points
					stats[2] += option;
					points -= option;
					pointConfirm = false;
				}
			}
			pointConfirm = true;
			break;

		case 4: // Charisma
			while (pointConfirm) {
				// Receives and validates user input
				std::cout << "How many points would you like to enter for Charisma?" << std::endl;
				while (!(std::cin >> option) || (option <= LOW_STAT || option >= MAX_STAT)) {
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					std::cout << "How many points would you like to enter for Charisma?" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				// Further input validation
				temp1 = option + stats[3];
				temp2 = points - option;
				if (option == 0) { // Allows the player to add 0 points to a stat/leave the stat without changing it
					pointConfirm = false;
				}
				else if (temp1 <= tempStats[3] - 1) { // This makes sure that the player doesn't go below their race/role stats
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (temp1 > MAX_STAT - 1) { // This stops a weird edge case where specific stats can go above 20
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (option < 0 && (temp1 > tempStats[3] && temp1 < stats[3])) { // Allows the user to take away points
					stats[3] += option;
					points -= option;
					pointConfirm = false;
				}
				else if (temp2 < 0) { // This stops the player from investing more points than they currently have
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (points == 0) { // This stops the user from investing more points if they have 0
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else { // This allows the user to actually invest their points
					stats[3] += option;
					points -= option;
					pointConfirm = false;
				}
			}
			pointConfirm = true;
			break;

		case 5: // Knowledge
			while (pointConfirm) {
				// Receives and validates user input
				std::cout << "How many points would you like to enter for Knowledge?" << std::endl;
				while (!(std::cin >> option) || (option <= LOW_STAT || option >= MAX_STAT)) {
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					std::cout << "How many points would you like to enter for Knowledge?" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				// Further input validation
				temp1 = option + stats[4];
				temp2 = points - option;
				if (option == 0) { // Allows the player to add 0 points to a stat/leave the stat without changing it
					pointConfirm = false;
				}
				else if (temp1 <= tempStats[4] - 1) { // This makes sure that the player doesn't go below their race/role stats
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (temp1 > MAX_STAT - 1) { // This stops a weird edge case where specific stats can go above 20
					system("cls");
					std::cout << "ERROR: INPUT NOT VALID!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (option < 0 && (temp1 > tempStats[4] && temp1 < stats[4])) { // Allows the user to take away points
					stats[4] += option;
					points -= option;
					pointConfirm = false;
				}
				else if (temp2 < 0) { // This stops the player from investing more points than they currently have
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else if (points == 0) { // This stops the user from investing more points if they have 0
					system("cls");
					std::cout << "ERROR: You do not have enough points!" << std::endl << "ENTER A NEW INPUT" << std::endl;
					std::cout << "These are " << name << "'s current stats:" << std::endl;
					for (int j = 0; j < 5; j++) {
						std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
						placement++;
					}
					placement = 1;
					switch (points) {
					case 1:
						std::cout << "You have " << points << " point left to spend" << std::endl;
						break;

					default:
						std::cout << "You have " << points << " points left to spend" << std::endl;
					}
					continue;
				}
				else { // This allows the user to actually invest their points
					stats[4] += option;
					points -= option;
					pointConfirm = false;
				}
			}
			pointConfirm = true;
			break;
		}
		if (points == 0) {
			system("cls");
			std::cout << "You have ran out of points!\nAre you happy with " << name << "'s stats?" << std::endl;
			for (int j = 0; j < 5; j++) {
				std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
				placement++;
			}
			std::cout << std::endl;
			placement = 1;
			std::cout << "1 - Yes\n2 - No" << std::endl;
			while (!(std::cin >> option) || (option <= 0 || option >= 3)) {
				std::cout << "ERROR: INPUT NOT VALID!\nENTER A NEW INPUT\n" << "You have ran out of points!\nAre you happy with " << name << "'s stats?" << std::endl;
				for (int j = 0; j < 5; j++) {
					std::cout << placement << ". " << statNames[j] << " " << stats[j] << std::endl;
					placement++;
				}
				placement = 1;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			switch (option) {
			case 1:
				hasPoints = false;
				system("cls");
				break;
			case 2:
				break;
			}
		}
		else {
			continue;
		}
	}
}

// This method resets all of the player object's stats
void Player::reset() {
	race = 0;
	role = 0;
	name = "";
	hasMagic = false;
	talkToAnimals = false;
	for (int i = 0; i < 5; i++) {
		stats[i] = 0;
	}
}

// This method will change a stat's value
void Player::changeStat(int statNum, int newStat) {
	stats[statNum] = newStat;
}

// This method gets the value for talkToAnimals
bool Player::getAnimal() {
	return talkToAnimals;
}
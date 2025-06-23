#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "character.h"
#include "warrior.h"
#include "archer.h"
#include "mage.h"
#include "enemy.h"
#include "level.h"

using namespace std;

vector<Level*> levels(5);
Character *hero;

void createHero() {
	string name;
	int option;

	cout << "______________________________" << endl;
    cout << "      Welcome to Eldoria     " << endl;
    cout << "______________________________" << endl;

	cout << "What is your hero's name? ";
	cin >> name;
	cin.ignore();

	cout << "What kind of hero do you want to be? \n";
	cout << "0. Warrior\n";
	cout << "1. Archer\n";
	cout << "2. Mage\n";
	cout << "Your choice:  ";
	cin >> option;

	option %= 3;

	switch(option) {
		case 0 : hero = new Warrior(name); break;
		case 1 : hero = new Archer(name); break;
		case 2 : hero = new Mage(name); break;
	}
}

void createLevels() {
	levels[0] = new Level("The Duel in the Goblin's Lair");
	levels[0]->addPrologue("The hero entered a foggy forest. Twisted trees whispered secrets. In a moonlit clearing, a mighty goblin appeared, ready to battle.");
	levels[0]->addEpilogue("The hero bravely defeated the goblin. Exhausted but victorious, he looked at the sunrise, ready for future challenges.");
	levels[0]->addEnemy(new Enemy("Goblin", 25, 15, 5));
	levels[0]->addHero(hero);

	levels[1] = new Level("The Curse of the Haunted Marsh");
	levels[1]->addPrologue("As the hero entered the marsh, thick fog clung to the ground. Whispering voices echoed from the water. A witch emerged, cloaked in shadows, chanting ancient spells. \n");
	levels[1]->addEpilogue("The witch let out a final shriek before dissolving into mist. The marsh fell silent. The hero, heart pounding, continued forward through the damp darkness. \n");
	levels[1]->addEnemy(new Enemy("Witch", 45, 30, 10));
	levels[1]->addHero(hero);

	levels[2] = new Level("The Battle of the Shadow Cave");
	levels[2]->addPrologue("The cave was dark and damp, with stalactites, bats, and an oppressive atmosphere. An orc awaited the hero by a fire.");
	levels[2]->addEpilogue("The hero, bleeding but victorious, defeated the orc. Exhausted, he picked up his sword and set out for new adventures.");
	levels[2]->addEnemy(new Enemy("Orc", 75, 45, 15));
	levels[2]->addHero(hero);

	levels[3] = new Level("The Blood Moon Duel");
	levels[3]->addPrologue("Under a blood-red moon, the hero entered a ruined cathedral. Shadows twisted unnaturally. A vampire descended from the rafters, fangs bared and eyes burning with hunger.");
	levels[3]->addEpilogue("The vampire crumbled into ash with a piercing scream. Moonlight returned to silver. The hero wiped blood from his blade and stepped back into the night.");
	levels[3]->addEnemy(new Enemy("Vampire", 80, 50, 25));
	levels[3]->addHero(hero);
	
	levels[4] = new Level("The Confrontation at the Frosty Peak");
	levels[4]->addPrologue("On the snowy mountaintop, the hero faced the red dragon. Icy wind whipped as the dragon roared, its scales glistening. Battle imminent.");
	levels[4]->addEpilogue("The hero stood over the fallen dragon. Wind scattered ashes. Sword smoking, he looked out over the snowy landscape, triumphant.");
	levels[4]->addEnemy(new Enemy("Dragon", 100, 60, 30));
	levels[4]->addHero(hero);

}

void deleteAll() {
	for (Level *lvl : levels) {
		delete lvl;
	}
}

void showStats(Character* c) {
    cout << "Name: " << c->getName()
         << " | Health: " << c->getHealth()
         << " | Mana: " << c->getMana()
         << " | Strength: " << c->getStrenght()
         << " | Shield: " << c->getShield() << endl;
}


int main(int argc, char* argv[]) {
    int i = 0; 
    bool finished = false;
    string restChoice;

    createHero();
    createLevels();

    cout << "\nIn the Kingdom of Eldoria, peace is shattered when the "
         << "necromancer Sarvok seeks the Stone of Eternity to gain "
         << "unlimited power.\nGuided by a prophecy, three heroes—a "
         << "Warrior, an Archer, and a Mage—set out on a journey to stop "
         << "Sarvok from achieving his goal, facing many dangers along the way.\n";
    cout << "____________________________________________________________\n";

    while (!finished && i < levels.size()) {
        cout << "\n\n__________ LEVEL " << (i + 1) << " __________" << endl;

        levels[i]->execute();

        if (!levels[i]->hasWon()) {
            finished = true;
        } else {
            cout << "\n" << hero->toString() << "\n";

            cout << "\nDo you want to rest and recover before the next battle? (yes/no): ";
            cin >> restChoice;
            cin.ignore();

            if (restChoice == "yes" || restChoice == "Yes") {
                cout<<"\n[RESTING...] \n";
				hero->recover();
                cout<<"You feel a bit stronger...\n";
				cout<<"After resting: \n";
				showStats(hero);
            } else {
                cout<<"\n You march forward without rest.\n";
            }
        }
        i++;
    }

    if (i >= levels.size() && levels[i-1]->hasWon()) {
        cout << "\n_________________________________________________\n";
        cout << "After arduous battles, the heroes reached the Dark Fortress\n"
             << "and defeated Sarvok, sealing the Eternity Stone.\n"
             << "Eldoria flourished and the heroes were celebrated.\n"
             << "Their legacy continues to inspire peace and justice.\n";
        cout << "_________________________________________________\n";
    }

    deleteAll();
	delete hero;
    return 0;
}



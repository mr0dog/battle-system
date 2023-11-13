#include <iostream>
using namespace std;
int health = 100;
string inventory[5] = { "sword", "shield", "potion"," ", " " };

void battlesystem();

int main() {
	int room = 1;
	char input = 'a';
	//for (int i = 0; i < 10; i++)
	 //inventory[i] = " ";
       
	while (health > 0) {

		cout << "your inventory: ";
		for (int i = 0; i < 5; i++)
			cout << inventory[i] << " ";
		cout << endl;

		switch (room) {
		case 1:
			cout << "your in room 1 you can go (s)outh" << endl;
			cin >> input;
			if (input == 's')
				room = 2;
			break;
		case 2:
			battlesystem();
			cout << "your in room 2 you can go (n)orth" << endl;
			cin >> input;
			if (input == 'n')
				room = 1;
			else if (input == 'a')
				battlesystem();
			if (health <= 0)
				break;
		}//end of switch
	}//end game loop
}//end of main

void battlesystem() {
	cout << "battle commencing" << endl;
	int monsterhealth = 50;
	char input;
	while (health >= 0 && monsterhealth > 0) {
		if (inventory[1] == "shield") {

			cout << "the monster bites toy for 5 hp" << endl;
			health -= 5;
		}
		else {
			cout << "the monster bites you for 10 hp" << endl;
			health -= 10;
		}
		if (inventory[0] == "sword") {
			cout << "you hit the monster for 30 hp" << endl;
			monsterhealth -= 30;
		}
		else {
			cout << "you punch the monster for 3 damage" << endl;
			monsterhealth -= 3;
		}
		
		cout << "your health: " << health << ". mobster health:" << monsterhealth << endl;
		system("pause");

		if(health>0)
		cout << "you can (f)ight, (r)un, or use (p)otion" << endl;
		cin >> input;
		if (input == 'r') {
			int num = rand() % 100;
			if (num < 40) {
				cout << "you escape the battle" << endl;
				break;
			}
			else
				cout << "chance to run failed :(" << endl;

		}
		if (input == 'p') {
			if (inventory[2] == "potion") {
				cout << "glug glug" << endl;
				health += 35;
				inventory[2] = " ";
			}

		}
		if (input == 'f') cout << "the battle contiues..." << endl;
	}//end of iser choice section
}//end of funk

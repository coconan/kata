#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const string weapons[3] =  { "sword", "bomb", "arrow" };
const string warriors[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
int warriorCost[5];
enum WarriorEnum { DRAGON, NINJA, ICEMAN, LION, WOLF };
const WarriorEnum redOrder[5] = {ICEMAN, LION, WOLF, NINJA, DRAGON};
const WarriorEnum blueOrder[5] = {LION, DRAGON, NINJA, ICEMAN, WOLF};

class Headquarter {
private:
	string name;
	int nLifeOrb;
	WarriorEnum warriorOrder[5];
	int warriorCounter[5];
	int minCost;
	int nextWarrior;
	bool stop;
	int numWarrior;
public:
	Headquarter(string _name, int _nLifeOrb, const WarriorEnum * _warriorOrder, int _minCost)
		: nLifeOrb(_nLifeOrb), stop(false), name(_name), minCost(_minCost), nextWarrior(0) {
		numWarrior = 0;
		for (int i = 0; i < 5; i++) {
			warriorOrder[i] = _warriorOrder[i];
			warriorCounter[i] = 0;
		}
	}

	string getName() { return name; }
	int getNumLifeOrb() { return nLifeOrb; }
	bool isStop() { return stop; }

	int getNumDragon() { return warriorCounter[0]; }
	int getNumNinja()  { return warriorCounter[1]; }
	int getNumIceman() { return warriorCounter[2]; }
	int getNumLion()   { return warriorCounter[3]; }
	int getNumWolf()   { return warriorCounter[4]; }

	void trainWarrior();
};

class Warrior {
private:
	string name;
	int id;
	int strength;
	Headquarter * h;
public:
	Warrior(string _name, int _id, int _strength, Headquarter * _h)
		: name(_name), id(_id), strength(_strength), h(_h) {
		cout << name << " " << id << " born with strength " << strength << ",";
	}
	
	int getId() { return id; }
	int getStrength() { return strength; }
};

class Dragon: public Warrior {
private:
	string w;
	double morale;
public:
	Dragon(int id, int strength, Headquarter * h): Warrior("dragon", id, strength, h) {
		morale = 1.0 * h->getNumLifeOrb() / getStrength();
		w = weapons[getId() % 3];
		cout << h->getNumDragon() + 1 << " dragon in " << h->getName() << " headquarter" << endl;
		cout << "It has a " << w << ",and it's morale is " << morale << endl;
	}
};

class Ninja: public Warrior {
private:
	string w1, w2;
public:
	Ninja(int id, int strength, Headquarter * h): Warrior("ninja", id, strength, h) {
		w1 = weapons[getId() % 3];
		w2 = weapons[(getId()+1) % 3];
		cout << h->getNumNinja() + 1 << " ninja in " << h->getName() << " headquarter" << endl;
		cout << "It has a " << w1 << " and a " << w2 << endl;
	}
};

class Iceman: public Warrior {
private:
	string w;
public:
	Iceman(int id, int strength, Headquarter * h): Warrior("iceman", id, strength, h) {
		w = weapons[getId() % 3];
		cout << h->getNumIceman() + 1 << " iceman in " << h->getName() << " headquarter" << endl;
		cout << "It has a " << w << endl;
	}
};

class Lion: public Warrior {
private:
	int loyalty;
public:
	Lion(int id, int strength, Headquarter * h): Warrior("lion", id, strength, h) {
		loyalty = h->getNumLifeOrb();
		cout << h->getNumLion() + 1 << " lion in " << h->getName() << " headquarter" << endl;
		cout << "It's loyalty is " << loyalty << endl;
	}
};

class Wolf: public Warrior {
public:
	Wolf(int id, int strength, Headquarter * h): Warrior("wolf", id, strength, h) {
		cout << h->getNumWolf() + 1 << " wolf in " << h->getName() << " headquarter" << endl;
	}
};


void Headquarter::trainWarrior() {
	if (stop) return;
	if (nLifeOrb < minCost) {
		cout << "headquarter stops making warriors" << endl;
		stop = true;
		return;
	}

	bool success = false;
	while (!success) { 
		Warrior * w;
		WarriorEnum next = warriorOrder[nextWarrior];
		if (nLifeOrb >= warriorCost[next]) {
			nLifeOrb -= warriorCost[next];
			success = true; numWarrior++;
			switch (next) {
			case DRAGON: w = new Dragon(numWarrior, warriorCost[DRAGON], this); break;
			case NINJA:  w = new Ninja(numWarrior, warriorCost[NINJA], this); break;
			case ICEMAN: w = new Iceman(numWarrior, warriorCost[ICEMAN], this); break;
			case LION:   w = new Lion(numWarrior, warriorCost[LION], this); break;
			case WOLF:   w = new Wolf(numWarrior, warriorCost[WOLF], this); break;
			}
			warriorCounter[next] = warriorCounter[next] + 1;
			delete w;
		}
		nextWarrior = (nextWarrior + 1) % 5;
	}
}

int main() {
	int numCases, numLifeOrb;
	cin >> numCases;
	for (int i = 0; i < numCases; i++) {
		cin >> numLifeOrb;
		int minCost = 10000;
		for (int j = 0; j < 5; j++) {
			cin >> warriorCost[j];
			if (minCost > warriorCost[j]) {
				minCost = warriorCost[j];
			}
		}

		cout << "case: " << i+1 << endl;
		Headquarter red("red", numLifeOrb, redOrder, minCost);
		Headquarter blue("blue", numLifeOrb, blueOrder, minCost);
		for (int step = 0; !red.isStop() || !blue.isStop(); step++) {
			if (!red.isStop()) {
				printf("%03d red ", step);
				red.trainWarrior();
			}
			if (!blue.isStop()) {
				printf("%03d blue ", step);
				blue.trainWarrior();
			}
		}
	}
	return 0;
}
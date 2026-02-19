#include <iostream>
using namespace std;

class Weapons {
public:
    void WeaponsDescription() {
        cout << "Weapons are tools which are used to cause damage or destruction. Sometimes they are used in self=defense." << endl;
    }
};

class HotWeapons : public Weapons {
public:
    void HotWeaponsDescription() {
        cout << "Hot weapons use gunpowder, heat, or explosive materials to function." << endl;
    }
};

class Bombs : public HotWeapons {
public:
    void BombsDescription() {
        cout << "Bombs are explosive weapons that blow up targets. i.e Grenades, Mines etc." << endl;
    }
};

class NuclearBombs : public Bombs {
public:
    void NuclearBombsDescription() {
        cout << "Nuclear bombs cause massive explosions using nuclear fission and fusion." << endl;
    }
};

int main() {

    NuclearBombs nb;

    // Because of multilevel inheritance,
    // NuclearBombs can access all parent methods

    nb.WeaponsDescription();
    cout  << endl;
    nb.HotWeaponsDescription();
    cout  << endl;
    nb.BombsDescription();
    cout  << endl;
    nb.NuclearBombsDescription();

    return 0;
}

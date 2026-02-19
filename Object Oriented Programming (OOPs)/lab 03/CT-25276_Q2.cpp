#include <iostream>
using namespace std;

class Character
{
    // member variables
    int *health, *power, *defense;
public:
    // setter methods
    void setHealth(int input)
    {
        *health = input;
    }
    void setPower(int input)
    {
        *power = input;
    }
    void setDefense(int input)
    {
        *defense = input;
    }
    // getter methods
    int getHealth()
    {
        return *health;
    }
    int getPower()
    {
        return *power;
    }
    int getDefense()
    {
        return *defense;
    }
    // Constructors
    Character()
    {
        health = new int(100);
        power = new int(0);
        defense = new int(0);
    }
    Character(int h, int p, int d)
    {
        health = new int(h);
        power = new int(p);
        defense = new int(d);
    }
    Character(const Character &obj)
    {
        health = new int(*(obj.health));
        power = new int(*(obj.power));
        defense = new int(*(obj.defense));
    }
};

int main()
{
    Character a, b(80, 200, 500);
    Character c = a;

    cout << "Character A:" << endl
         << "Health: " << a.getHealth() << endl
         << "Power: " << a.getPower() << endl
         << "Defense: " << a.getDefense() << endl
         << endl;

    cout << "Character B:" << endl
         << "Health: " << b.getHealth() << endl
         << "Power: " << b.getPower() << endl
         << "Defense: " << b.getDefense() << endl
         << endl;

    cout << "Character C:" << endl
         << "Health: " << c.getHealth() << endl
         << "Power: " << c.getPower() << endl
         << "Defense: " << c.getDefense() << endl;

    return 0;
}

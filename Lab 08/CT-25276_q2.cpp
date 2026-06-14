#include <iostream>
using namespace std;


class Character {
protected:
    string name;
    int    level;
    int    health;

public:
    Character(string name, int level, int health)
        : name(name), level(level), health(health) {}

    
    virtual void attack() const {
        cout << name << " attacks!\n";
    }

    virtual void display() const {
        cout << "Name: "   << name
             << " | Level: " << level
             << " | HP: "    << health << "\n";
    }

    string getName()  const { return name; }
    int    getLevel() const { return level; }
    int    getHealth()const { return health; }

    virtual ~Character() {}
};



class Warrior : public Character {
protected:
    int    strength;
    string meleeWeapon;     

public:
    Warrior(string name, int level, int health, int strength, string weapon)
        : Character(name, level, health),
          strength(strength), meleeWeapon(weapon) {}

   
    void slash() const {
        cout << name << " slashes with " << meleeWeapon
             << "! (Strength: " << strength << ")\n";
    }

    void attack() const override {
        slash();
    }

    void display() const override {
        Character::display();
        cout << "  [Warrior] Strength: " << strength
             << " | Weapon: " << meleeWeapon << "\n";
    }
};



class Mage : public Character {
protected:
    int    intelligence;
    string spellProficiency;   

public:
    Mage(string name, int level, int health, int intelligence, string spell)
        : Character(name, level, health),
          intelligence(intelligence), spellProficiency(spell) {}

    
    void fireball() const {
        cout << name << " casts Fireball! ("
             << spellProficiency << " magic, INT: " << intelligence << ")\n";
    }

    void attack() const override {
        fireball();
    }

    void display() const override {
        Character::display();
        cout << "  [Mage] Intelligence: " << intelligence
             << " | Spell: " << spellProficiency << "\n";
    }
};



class Archer : public Character {
protected:
    int    dexterity;
    string rangedWeapon;    

public:
    Archer(string name, int level, int health, int dexterity, string weapon)
        : Character(name, level, health),
          dexterity(dexterity), rangedWeapon(weapon) {}

    
    void rapidShot() const {
        cout << name << " fires Rapid Shot with " << rangedWeapon
             << "! (DEX: " << dexterity << ")\n";
    }

    void attack() const override {
        rapidShot();
    }

    void display() const override {
        Character::display();
        cout << "  [Archer] Dexterity: " << dexterity
             << " | Weapon: " << rangedWeapon << "\n";
    }
};



class NPC : public Character {
private:
    string movementPattern;  
    string dialogue;

public:
    NPC(string name, int level, int health,
        string movement, string dialogue)
        : Character(name, level, health),
          movementPattern(movement), dialogue(dialogue) {}

    
    void move() const {
        cout << name << " moves in pattern: " << movementPattern << "\n";
    }

    void speak() const {
        cout << name << " says: \"" << dialogue << "\"\n";
    }

    void attack() const override {
        cout << name << " (NPC) has no attack!\n";
    }

    void display() const override {
        Character::display();
        cout << "  [NPC] Movement: " << movementPattern
             << " | Dialogue: \"" << dialogue << "\"\n";
    }
};



class Mighty : public Warrior, public Mage {
private:
    string title;   

public:
    Mighty(string name, int level, int health,
           int strength, string weapon,
           int intelligence, string spell,
           string title)
        : Warrior(name, level, health, strength, weapon),
          Mage(name, level, health, intelligence, spell),
          title(title) {}

    
    void attack() const override {
        cout << "=== " << title << " unleashes combined attack! ===\n";
        slash();       
        fireball();    
    }

    void display() const override {
       
        cout << "Name: "    << Warrior::name
             << " | Level: " << Warrior::level
             << " | HP: "    << Warrior::health << "\n";
        cout << "  [Mighty - " << title << "]\n";
        cout << "  Strength: "     << strength
             << " | Weapon: "      << meleeWeapon << "\n";
        cout << "  Intelligence: " << intelligence
             << " | Spell: "       << spellProficiency << "\n";
    }

    
    string getName() const { return Warrior::name; }
};



int main() {

    cout << "========== Warrior ==========\n";
    Warrior w("Aragorn", 10, 250, 85, "Sword");
    w.display();
    w.attack();
    w.slash();

    cout << "\n========== Mage ==========\n";
    Mage m("Gandalf", 15, 180, 95, "Arcane");
    m.display();
    m.attack();
    m.fireball();

    cout << "\n========== Archer ==========\n";
    Archer a("Legolas", 12, 200, 90, "Longbow");
    a.display();
    a.attack();
    a.rapidShot();

    cout << "\n========== NPC ==========\n";
    NPC npc("Village Elder", 1, 50, "Patrol", "Beware the dark forest!");
    npc.display();
    npc.move();
    npc.speak();

    cout << "\n========== Mighty ==========\n";
    Mighty mighty("Zephyros", 20, 400,
                  90, "Runic Axe",
                  88, "Fire",
                  "The Arcane Warlord");
    mighty.display();
    mighty.attack();

    cout << "\n========== Polymorphism Demo ==========\n";
    
    Character* party[] = { &w, &m, &a };
    for (auto* c : party) {
        cout << c->getName() << ": ";
        c->attack();
    }

    return 0;
}
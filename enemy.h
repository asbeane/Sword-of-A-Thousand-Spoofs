#include <string>

using namespace std;

class Enemy
{
private:
    string name;
    int MaxHP;
    int currentHP;
    int attack;
    int defense;
public:
    Enemy(string _name, int hp, int attk, int def);
    string getName();
    int getMaxHP();
    int getCurrentHP();
    void setCurrentHP(int value);
    int getAttack();
    int getDefense();
    int getCombatChoice(int& cooldown_heavy);
};

class StrongerEnemy: public Enemy
{
private:
    Item_Weapon equipped_weapon;
    Item_Armor equipped_armor;
public:
    StrongerEnemy(string _name, int hp, int attk, int def);
    int getAttack();
    int getDefense();
    int getCombatChoice(int& cooldown_heavy, int& cooldown_dodge);
};


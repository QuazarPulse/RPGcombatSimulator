#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>

class Personnage
{
public:

    Personnage(); //constructeur
    void receiveDamage(int damage);
    void attack(Personnage &cible);
    void heal();
    void changeWeapon(string newWeaponName, int newWeaponDamagePerShot, int newWeaponShotPerSecond);
    void changeArmor(string newArmorName, int newArmorArmor, int newArmorShield);
    bool isAlive();
    bool isTurnOver();

    private:

    int m_life;
    int m_armor;
    int m_shield;
    int m_precision;
    int m_time;
    int m_speed;
    int m_weaponDamagePerShot;
    int m_weaponShotPerSecond;
    std::string m_weaponName;
    std::string m_armorName;
    int m_healPacks;
};

#endif // PERSONNAGE_H_INCLUDED

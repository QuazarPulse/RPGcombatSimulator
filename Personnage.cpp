#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include Personnage.h

using namespace std;


void Personnage::receiveDamage(int damage)
{
    double tempShield = 1 - (m_shield / 100);
    damage *= tempShield;
    m_life -= damage;
    if (m_life < 0)
    {
        m_life=0;
    }
}
void Personnage::attack(Personnage &cible)
{
    int compteur(0), succesfullShots(0);
    int numberOfShots = ceil(m_time * m_weaponShotPerSecond);
    for (compteur = 0 ; compteur < numberOfShots ; compteur++)
    {
        int randomV = rand() % 100 + 1;
        if (randomV <= m_precision)
        {
             succesfullShots++;
        }
    }
    int damage = succesfullShots * m_weaponDamagePerShot;
    m_time = 0;
    cout << "You have been hit by the target " << succesfullShots << " times, taking " << damage << " damage points!" << endl;
    cible.receiveDamage(damage);
}
void Personnage::heal()
{
    if (m_healPacks = 0)
    {
        cout << "You don't have any MediKits" << endl;
    }
    else
    {
        m_healPacks--;
        m_life += 30;
        if (m_life > 100)
        {
            m_life = 100;
        }
        cout << "You now have " << m_life << " life points now!"
        m_time -= 5;
    }
}
void Personnage::changeWeapon(string newWeaponName, int newWeaponDamagePerShot, int newWeaponShotPerSecond)
{
    m_weaponName = newWeaponName;
    m_weaponDamagePerShot = newWeaponDamagePerShot;
    m_weaponShotPerSecond = newWeaponShotPerSecond;
}
void changeArmor(string newArmorName, int newArmorArmor, int newArmorShield)
{
    m_armorName = newArmorName;
    m_armor = newArmorArmor;
    m_shield = newArmorShield;
}
bool Personnage::isAlive()
{
    if (m_life = 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool Personnage::isTurnOver()
{
    if (m_time = 0)
    {
        m_time = 10;
        return true;
    }
    else
    {
        return false;
    }
}




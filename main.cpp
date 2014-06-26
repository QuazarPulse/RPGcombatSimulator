#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Personnage
{
public:
    void receiveDamage(int damage)
    {
        double tempShield = 1 - (m_shield / 100);
        damage *= tempShield;
        m_life -= damage;
        if (m_life < 0)
        {
            m_life=0;
        }
    }
    void attack(Personnage &cible)
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
    void heal()
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
            cout << "You now have " << m_life << " life points now!" << endl;
            m_time -= 5;
        }
    }
    void changeWeapon(string newWeaponName, int newWeaponDamagePerShot, int newWeaponShotPerSecond)
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
    bool isAlive()
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
    bool isTurnOver()
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
    private:

    int m_life;
    int m_armor;
    int m_shield;
    int m_precision;
    int m_time;
    int m_speed;
    int m_weaponDamagePerShot;
    int m_weaponShotPerSecond;
    string m_weaponName;
    string m_armorName;
    int m_healPacks;

};

int main()
{
    cout << "You're using RPG Combat Simulator V2" << endl << "Created by Quazar" << endl;

    return 0;
}

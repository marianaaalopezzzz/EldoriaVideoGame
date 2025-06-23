#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std; 

class Character {
protected: 
    string name; 
    int health; 
    int mana; 
    int strenght; 
    int shield; 
public: 
    Character(); 
    Character(const Character&); 
    Character(string, int, int, int, int);

    string getName() const; 
    int getHealth() const; 
    int getMana() const; 
    int getStrenght() const; 
    int getShield() const; 

    void takeDamage(int); 
    bool isAlive() const; 

    virtual void attack(Character*) = 0; 
    virtual void recover() = 0; 
    virtual string toString() const = 0; 

    virtual ~Character() {}
}; 

//Constructor Default con valores de instancia vacios 
Character::Character()
    : name("noname"), health(1), mana(1), strenght(1), shield(1){
}

//Constructor de copia 
Character::Character(const Character &C)
    : name(C.name), health(C.health), mana(C.mana), strenght(C.strenght), shield(C.shield){
}

//Constructor
Character::Character(string n,int h, int m, int s, int sh)
    : name(n), health(h), mana(m), strenght(s), shield(sh){
}

string Character::getName() const{
    return name;
}

int Character::getHealth() const{  
    return health; 
}

int Character::getMana() const{
    return mana; 
}

int Character::getStrenght() const{
    return strenght;
}

int Character::getShield() const{
    return shield; 
}

//Calcula el daño real de mi personaje 
void Character::takeDamage(int damage){
    int realDamage = damage - shield; //A mi daño le restamos el escudo 
    if (realDamage > 0 ){ //Si el daño real es mayo que 0, o sea positivo 
        health = health - realDamage; //Restamos el daño real de la salud de mi personaje 
    }
}

bool Character::isAlive() const{
    if (health > 0){ //El personaje esta vivo si su salud es mayor que 0 
        return true; 
    }
    else {
        return false;
    }
}

#endif 

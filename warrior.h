#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#include "character.h"

using namespace std;

class Warrior : public Character{
public: 
    Warrior(); 
    Warrior(const Warrior&); 
    Warrior(string); 

    void attack(Character*) override; 
    void recover() override; 
    string toString() const override; 
};

//Constructor predeterminado con valores especificos 
Warrior::Warrior()
    : Character("Warrior", 80, 30, 40, 20){
}

Warrior::Warrior(const Warrior &W)
    : Character(W){
}

//Constructor que recibe un parametro pero matiene los 
//mismos valores prederminados para los demas atributos 
Warrior::Warrior(string n)
    :Character(n, 80, 30, 40, 20){
}

void Warrior::attack(Character* C){
    if (mana > 10){ //Si el mana es mayor de 10 
        C->takeDamage(strenght*2);//Ataque fuerte el cual cause el doble de daño
        mana = mana - 10;//Pero me quita 10 puntos de mana 
    }
    else{
        C->takeDamage(strenght); //If not pues un ataque normal 
    }
}

//Aumenta la salud de guerrero 
void Warrior::recover(){
    if (health + 10 <= 80){ //Checa que no pase el limite de salud para guerrero 
        health = health + 10; 
    }
    if (mana + 5 <= 30){//Checa que no pase el limite de mana para guerrero
        mana = mana + 5; 
    }
}

string Warrior::toString() const{
    stringstream ss; 
    ss<<"Name:  "<<name<<"  Health:  "<<health<<"  Mana:  "<<mana; 
    return ss.str(); 
}




#endif


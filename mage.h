#ifndef MAGE_H
#define MAGE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#include "character.h"

using namespace std;

class Mage : public Character{
public: 
    Mage(); 
    Mage(const Mage&); 
    Mage(string); 

    void attack(Character*) override;
    void recover() override;
    string toString() const override; 
};

//Constructor prederminado con 
Mage::Mage()
    :Character("Mage", 65, 100, 20, 10){
}

Mage::Mage(const Mage &M)
    : Character(M){
}

//Constructor que recibe un parametro pero matiene los 
//mismos valores prederminados para los demas atributos 
Mage::Mage(string n)
    :Character(n, 65, 100, 20, 10){
}

void Mage::attack(Character* C){
    if (mana > 30){ //Si el mana es mayor que 30
        C->takeDamage(strenght*4);//Ataque fuerte el cual causa el cuadruple de daño
        mana = mana - 30;//Pero me quita 30 puntos de mana 
    }
    else{
        C->takeDamage(strenght); //If not pues un ataque normal 
    }
}

//Aumenta la salud de arquero  
void Mage::recover(){
    if (health + 10 <= 65){ //Checa que no pase el limite de salud para mago
        health = health + 10; 
    }
    if (mana + 5 <= 100){//Checa que no pase el limite de mana para mago
        mana = mana + 5; 
    }
}

string Mage::toString() const{
    stringstream ss; 
    ss<<"Name:  "<<name<<"  Health:  "<<health<<"  Mana:  "<<mana; 
    return ss.str(); 
}

#endif

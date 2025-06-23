#ifndef ARCHER_H
#define ARCHER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#include "character.h"

using namespace std;

class Archer : public Character{
public: 
    Archer(); 
    Archer(const Archer&); 
    Archer(string); 

    void attack(Character*) override; 
    void recover() override; 
    string toString() const override; 
}; 
 //Constructor predeterminado con valores especificos
Archer::Archer()
    :Character("Archer", 60, 50, 30, 15){
}

Archer::Archer(const Archer &A)
    :Character(A){
}
//Constructor que recibe un parametro pero matiene los 
//mismos valores prederminados para los demas atributos 
Archer::Archer(string n)
    : Character(n, 60, 50, 30, 15){
}

void Archer::attack(Character* C){
    if (mana > 20){ //Si el mana es mayor que 20
        C->takeDamage(strenght*3);//Ataque fuerte el cual causa el triple de daño
        mana = mana - 20;//Pero me quita 20 puntos de mana 
    }
    else{
        C->takeDamage(strenght); //If not pues un ataque normal 
    }
}

//Aumenta la salud de arquero  
void Archer::recover(){
    if (health + 5 <= 60){ //Checa que no pase el limite de salud para arquero
        health = health + 5; 
    }
    if (mana + 10 <= 50){//Checa que no pase el limite de mana para arquero
        mana = mana + 10; 
    }
}

string Archer::toString() const{
    stringstream ss; 
    ss<<"Name:  "<<name<<"  Health:  "<<health<<"  Mana:  "<<mana; 
    return ss.str(); 
}

#endif 

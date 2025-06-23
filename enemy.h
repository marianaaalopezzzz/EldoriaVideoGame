#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#include "character.h"

using namespace std;

class Enemy : public Character{
public: 
    Enemy();
    Enemy(const Enemy&);
    Enemy(string, int, int, int);

    void attack(Character*) override; 
    void recover() override; 
    string toString() const override; 

};

//Constructor predeterminado con valores especificos 
Enemy::Enemy()
    : Character("Enemy", 30, 0, 15, 5){
}

Enemy::Enemy(const Enemy &E)
    : Character(E){
}

//Constructor que recibe 4 parametro pero matiene los 
//el mana con su valor predeterminado 
Enemy::Enemy(string n,int h,int s, int sh)
    :Character(n, h, 0, s, sh){
}

//El enemigo puede atacar otros personajes 
void Enemy::attack(Character* c){
    c->takeDamage(strenght);//el daño es igual a la fuerza  
}

//Aumenta la salud del enemigo 
void Enemy::recover(){
    if (health + 10 <= 100){ //Checa que no pase el limite de salud para enemigo
        health = health + 10; 
    }
    if (mana + 5 <= 60){//Checa que no pase el limite de mana para enemigo
        mana = mana + 5; 
    }
}

string Enemy::toString() const{
    stringstream ss; 
    ss<<"Name:  "<<name<<"  Health:  "<<health<<"  Mana:  "<<mana; 
    return ss.str(); 
}





#endif

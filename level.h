#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "character.h"
#include "enemy.h"

using namespace std; 

class Level{
private: 
    string name;
    Character* hero;
    Character* enemy;
    string prologue;
    string epilogue;
    bool won;
public: 
    Level();
    Level(const Level&);
    Level(string);

    ~Level();

    bool hasWon(); 
    void addPrologue(string);
    void addEpilogue(string); 
    void addEnemy(Enemy*); 
    void addHero(Character*);
    void execute(); 

};

Level::Level()
    :name("DefaultLevel"), hero(nullptr), enemy(nullptr), prologue("DefaultPrologue"), epilogue("DefaultEpilogue"), won(false){
}

//Constrctor de copia 
//Me ayuda copiar los atributos basico si hay un enemigo en el nivel original
//se crea una nueva copia del enemigo para el nuevo nivel
Level::Level(const Level &L)
    :name(L.name), hero(L.hero), prologue(L.prologue), epilogue(L.epilogue), won(L.won){
        if (L.enemy != nullptr){
            enemy = new Enemy(*(Enemy*)L.enemy);
        } 
        else{
            enemy = nullptr;
        }
}

Level::Level(string n)
    :name(n), hero(nullptr), enemy(nullptr), prologue("DefaultPrologue"), epilogue("DefaultEpilogue"), won(false){
}

//Destructor que libera la memoria de enemy asignado dinamicamente
Level::~Level(){
    if (enemy != nullptr){
        delete enemy; 
        enemy = nullptr;
    }
}

bool Level::hasWon(){
    return won; 
}

void Level::addPrologue(string p){
    prologue = p;
}

void Level::addEpilogue(string e){
    epilogue = e;
}

//Se añade un enemigo al nivel 
//si ya hay un enemigo, se elimina primero para que no haya fugas de memoria 
//y de que crea una nueva instancia del enemy usando constructor de copia
void Level::addEnemy(Enemy* e){
    if(enemy !=nullptr){ //Libera el enemigo anterior si existe
        delete enemy;
    }
    enemy = new Enemy(*e); //nueva copia del enemigo 
}

void Level::addHero(Character* h){
    hero = h;
}

void Level::execute(){
    //Checamos si hero fue asignado antes de iniciar el nivel
    if (hero == nullptr){
        cout << "No hero assigned. \n";
        won = false;
        return; 
    }
    //Checamos si enemigo fue asignado antes de inicar nivel
    if(enemy == nullptr){
        cout<<"No enemy assigned. \n"; 
        won = false;
        return;
    }

    //Nos ayuda a mostarr las estadisticas de cada personaje 
    auto showStats = [](Character* C) {
        cout << "Name: " << C->getName()
             << " | Health: " << C->getHealth()
             << " | Mana: " << C->getMana()
             << " | Strength: " << C->getStrenght()
             << " | Shield: " << C->getShield() << endl;
    };

    cout << "\n_________________________________________________\n";
    cout <<"Level:  "<<name<<endl;
    cout<<prologue<<endl;

    string choice; 

    //Batalla mientras ambos estan vivos
    while(hero->isAlive() && enemy->isAlive()){
        cout<<"\n[HERO TURN]  \n";
        cout<<"Before attack: \n";
        showStats(hero);
        hero->attack(enemy); //Hero ataca a enemigo
        cout<<"\n After attack: \n";
        showStats(enemy);

        if(!enemy->isAlive()){ //Si el enemigo muere despues de que ataca hero, ends 
            break;
        }

        cout<<"\n[ENEMY TURN]  \n";
        cout<<"Before attack: \n";
        showStats(enemy);
        enemy->attack(hero); //Enemy ataca a heroe 
        cout<<"\n After attack: \n";
        showStats(hero);
        

        if(!hero->isAlive()){ //Si el heroe muere despues de que atacara enemigo, ends
            break; 
        }

        //Opción para huir 
        cout<<"\nRun away? (yes/no):  ";
        cin >> choice; 

        if(choice == "yes" || choice =="Yes"){ //Por si lo ponen como mayuscula 
            cout<<"You ran away. \n";
            won = false; //Hero pierde si huye 
            return;
        }
    }

    if (hero->isAlive()){
        cout << "\n You won!! \n";
        cout << epilogue << endl;
        won = true; 
    }
    else{
        cout << "\n You lost. \n";
        won = false;
    }

    cout << "_________________________________________________\n";
}

#endif 

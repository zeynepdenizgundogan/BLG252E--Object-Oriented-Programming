//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

const string pokemon::get_name()const{
    return this->name;
}

const int pokemon::get_HP()const{
    return this->hpValue;
}

const int pokemon::get_atk_value()const{
    return this->atkValue;
}

void pokemon::set_HP(int newHP){
    this->hpValue=newHP;
}
pokemon::pokemon(){
    name="";
    hpValue=100;
    atkValue=0;

}

pokemon::pokemon(const string name, const int atkValue, const int hpValue) : hpValue(hpValue){
    this->atkValue=atkValue;
    this->name=name;
}

pokemon::pokemon(const pokemon& p){
    name=p.name;
    atkValue=p.atkValue;
    hpValue=p.hpValue;

}
pokedex::pokedex(){
    value=0;
}

void pokedex::printPokedex() const{
   
    for (int i=0;i<value;i++){
    cout<<pokedexArray[i].get_name()<<endl;
    }
}

void pokedex::updatePokedex(const pokemon& p){
    bool checker=false;
   
    for (int i=0; i<value;i++){
        if(pokedexArray[i].get_name()==p.get_name()){
            checker=true;
        }
    }  
    if(checker==false){
        pokedexArray[value]=p;
        value++;
    } 
}

player::player(){
    
    pokemonNumber=0;
    pokeballNumber=10;
    badgeNumber=0;

};

player::player(const string name, const pokemon &p){
    this->name=name;
    pokemonNumber=0;
    pokeballNumber=10;
    badgeNumber=0;
    playerPokemon=p;
}

const int player::showPokemonNumber()const{
    return this->pokemonNumber;
}

const int player::showBadgeNumber()const{
    return this->badgeNumber;
}

const int player::showPokeballNumber()const{
    return this->pokeballNumber;
}

void player::battleWon(){
    pokeballNumber+=3;
    badgeNumber+=1;
}

void player::catchPokemon(){
    pokeballNumber-=1;
    pokemonNumber+=1;
}

const pokemon player::getPokemon()const{
    return this-> playerPokemon;
}
enemy::enemy(){
    name="";
}

enemy::enemy(const string name, const pokemon &p){
    
    enemyPokemon=p;
    this->name=name;
}

const string enemy::getName()const{
    return this->name;
}

const pokemon enemy::getPokemon()const {
     return this-> enemyPokemon;
}
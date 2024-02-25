//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
    const string get_name()const;
    const int get_HP()const;
    const int get_atk_value()const;
    void set_HP(int);
    pokemon();
    pokemon(const string, const int, const int=100);
    pokemon(const pokemon&);
    void damage(int damage){
        this->hpValue-=damage; //function for decreasing hp value
    };
};

class pokedex{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        pokemon pokedexArray[100];
        int value;
    public:
    pokedex();
    void updatePokedex(const pokemon&);
    void printPokedex()const;
       
};

class player{
    private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;
        player();
        player( const string , const pokemon& );
        const int showPokemonNumber()const;
        const int showPokeballNumber()const;
        const int showBadgeNumber()const;  
        const pokemon getPokemon()const;
        void battleWon();
        void catchPokemon();
};

class enemy{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy();
        enemy(const string, const pokemon& );
        const pokemon getPokemon()const;
        const string getName()const;
};

#endif
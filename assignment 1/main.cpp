//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it

//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char* );
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//

//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//

string* readEnemyNames( const char* argv ){   
    ifstream inFile;
   
    inFile.open(argv,ifstream::in);
    string line;
    int i=0;

    getline(inFile,line);//reading the first line
    
    int num=stoi(line);//first line tells us the number of pokemons so I turn it into int from string

    string* enemyNames= new string[num];//creating the array

    while (getline(inFile, line)){
        
        enemyNames[i]=line;
        i++;

    }
    return enemyNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv ){
    
    ifstream inFile;
    inFile.open(argv ,ifstream::in);
    string line;
    int i=0;
    
    getline(inFile,line); //reading the first line
    int num=stoi(line);//first line tells us the number of pokemons so I turn it into int from string

    string* pokemonNames= new string[num]; //creating the array
    
    while (getline(inFile, line)){
        
        pokemonNames[i]=line;
        i++;


    }
    return pokemonNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    string name;

    switch(pokemonChoice){
    case 1:
        name="Bulbasaur";
        break;    
    case 2:
        name="Charmender";
        break;
    case 3:
        name="Squirtle";
        break;

    }
    pokemon newPokemon(name,PLAYER_POKEMON_ATTACK);
    player newPlayer(playerName, newPokemon);
    return newPlayer;

};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    int choice=0;
    pokemon pokeEnemy(pokemonNames[POK_COUNTER],ENEMY_POKEMON_ATTACK); //creating enemy pokemon
    enemy enemy(enemyNames[NAME_COUNTER], pokeEnemy);//creating enemy player
    pokemon playerPoke=newPlayer->getPokemon();// getting the pokemon of player
    newPlayer->playerPokedex.updatePokedex(pokeEnemy);

    cout<<"You encounter with "<< enemy.getName()<<" and his/hers pokemon "<<pokeEnemy.get_name()<<endl;
    cout<<pokeEnemy.get_name()<<" Health: "<<pokeEnemy.get_HP()<<" Attack: "<< pokeEnemy.get_atk_value()<<endl;

    while(choice!=2 && playerPoke.get_HP()>0 && pokeEnemy.get_HP()>0){
        cout<<endl;
        cout<<"1- Fight"<<endl;
        cout<<"2- Runaway"<<endl;
        cout << "Choice: ";
        cin>>choice;

        if(choice==1){
        
            playerPoke.damage(pokeEnemy.get_atk_value());//decreasing hp values
            pokeEnemy.damage(playerPoke.get_atk_value());
            cout<<"Your Pokemons Health: "<<playerPoke.get_HP()<<endl;
            cout<< enemy.getName()<<" Pokemons Health: "<<pokeEnemy.get_HP()<<endl;

            if(pokeEnemy.get_HP()<=0){
                cout<<"You Won!"<<endl;
                newPlayer->battleWon();  
            }
            else if(pokeEnemy.get_HP()>0 && playerPoke.get_HP()<=0){
                cout<<"You lost."<<endl;
            }

        }
        else if(choice==2){
            cout<<"You runaway."<<endl;
        }

    }
    POK_COUNTER++;
    NAME_COUNTER++;

};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    pokemon newPoke(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK);
    cout<<"You encounter with "<<newPoke.get_name()<< " Health: "<< newPoke.get_HP()<< " Attack: "<< newPoke.get_atk_value()<<endl;
    int choice;
        cout<<"1- Catch"<<endl;
        cout<<"2- Runaway"<<endl;
        cout << "Choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"You catch "<<newPoke.get_name()<<endl;
                newPlayer->catchPokemon();
                newPlayer->playerPokedex.updatePokedex(newPoke);
                break;
            case 2:
                //cout<<"You runaway"<<endl;
                newPlayer->playerPokedex.updatePokedex(newPoke);
                break;
        }
        POK_COUNTER++;
};
//--------------------------------------------//

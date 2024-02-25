//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------//
#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;
/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

Crew::Crew(int inMaxExp, int inMaxMnr, int inExpSize, int inMnrSize){
    crewMaintenanceCost=0;
    crewManufactureCost=0;
    this->explorerCrewSize=0;
    this->minerCrewSize=0;
    
    if(inMaxExp>5 || inMaxExp<1){
       this->maxExplorers=2;
    }
    else{
        this->maxExplorers=inMaxExp;
    }
    if(inMaxMnr>5 || inMaxMnr<1){
        this->maxMiners=2;
    }
    else{
        this->maxMiners=inMaxMnr;
    }

    if(inExpSize<0 || inExpSize>this->maxExplorers){
        inExpSize=this->maxExplorers;
    }

    if(inMnrSize<0 || inMnrSize>this->maxMiners){
        inMnrSize=this->maxMiners;
    }

    this->ExplorerCrew=new Explorer*[this->maxExplorers];
    this->MinerCrew=new Miner*[this->maxMiners];
    //I assigned explorer and miner object to array. So that it would be easy to delete at the end of the program
    for(int i=0;i<maxExplorers;i++){ExplorerCrew[i]=new Explorer("x",5.5,5);Robot::decrementID();}
    for (int i=0;i<maxMiners;i++){MinerCrew[i]=new Miner("x",5.5,5);Robot::decrementID();}

    for (int i=0;i<inExpSize;i++){
        Robot* newRobot=manufactureRobot("explorer");//new robot to be added
        this->operator+=(newRobot);
        ExplorerCrew[i]->setCanMove(true);
        
    }

     for (int i=0;i<inMnrSize;i++){
        Robot* newRobot= manufactureRobot("miner");
        this->operator+=(newRobot);
        MinerCrew[i]->setCanMove(true);
    
    }
}

Robot* Crew::manufactureRobot(string newType){ //manufacture robot function with parameter
    int newManufactureCost;
    float newMaintenanceCost;
    int newDurability=(rand()%5)+1;
    float newSpeed;
    
    if(newType=="explorer"){
        newSpeed = (float(rand()) * 1.0 / float(RAND_MAX)) + 1.5;
        newManufactureCost=3000;
        newMaintenanceCost=450.0/newSpeed;
       
    }

    else if(newType=="miner"){
        newSpeed = ((float)rand() * 0.5 / (float)RAND_MAX) + 1.0;
        newManufactureCost=5000;
        newMaintenanceCost=750.0/newSpeed;
        
    }
    
    Robot* newRobot=new Robot(newType, newSpeed, newDurability, newManufactureCost, newMaintenanceCost);
    crewManufactureCost+=newManufactureCost;
    newRobot->setCanMove(false);
    return newRobot;

}

Robot* Crew::manufactureRobot(){//manufacture robot function with cin input
    string newType;
    int newManufactureCost;
    float newMaintenanceCost;
    int newDurability=(rand()%5)+1;
    float newSpeed;
    //I used do while, so that it will require user input if ther is invalid input
    do{
        cout<<"Type:";
        cin>>newType;
    }while(newType!="explorer" && newType!="miner");
    
    if(newType=="explorer"){
        
        newSpeed = (float(rand()) * 1.0 / float(RAND_MAX)) + 1.5;
        newManufactureCost=3000;
        newMaintenanceCost=450.0/newSpeed;
    } 
 
    else if( newType=="miner"){
        newSpeed = (float(rand()) * 0.5 / float(RAND_MAX)) + 1.0;
        newManufactureCost=5000;
        newMaintenanceCost=750.0/newSpeed;
    }    
    
    Robot* newRobot=new Robot(newType, newSpeed, newDurability, newManufactureCost, newMaintenanceCost);
        crewManufactureCost+=newManufactureCost;
        newRobot->setCanMove(false);
        return newRobot;
    }

void Crew::initMovement(){
    for (int i=0;i<explorerCrewSize;i++){
        ExplorerCrew[i]->setCanMove(true);
    }
    for(int i=0;i<minerCrewSize;i++){
        MinerCrew[i]->setCanMove(true);
    }
}

void Crew::operator+=(  Robot* r){
    
    if(explorerCrewSize!=maxExplorers &&r->getRobotType()=="explorer"){
        if(explorerCrewSize<maxExplorers){//if there is space in explorerCrew array we can add explorer robot
            
            *ExplorerCrew[explorerCrewSize]=*static_cast<Explorer*>(r); //I used static cast to change robot* to explorer*
            ExplorerCrew[explorerCrewSize++]->setCanMove(false);
            //crewManufactureCost+=r->getManufactureCost();

        }   
    }
    else if(minerCrewSize!=maxMiners &&r->getRobotType()=="miner"){
        if(minerCrewSize<maxMiners){//if there is space in minerCrew array we can add miner robot
           
            *MinerCrew[minerCrewSize] = *static_cast<Miner*>(r);//I used static cast to change robot* to miner*
            MinerCrew[minerCrewSize++]->setCanMove(false);
            //crewManufactureCost+=r->getManufactureCost();
        }   
    }
    
    else{
        crewManufactureCost=crewManufactureCost-r->getManufactureCost();
        cout<<"This robot cannot be added, check maximum size of the crew"<<endl;
    }
    delete r;
    r=NULL; 
}

void Crew::operator-=(const string& rName){
    int index=0;
    cout<<rName<<": Goodbye"<<endl;
    /*first I am finding the index of the robot with the matching name with rName
    since I dont know if it is in ExplorerCrew or MinerCrew I am making two for loops*/
    for(int i=0;i<explorerCrewSize;i++){
        if(rName == ExplorerCrew[i]->getName()){
            index=i;
            break;
        }
    }

    for(int i=0;i<minerCrewSize;i++){
        if(rName == MinerCrew[i]->getName()){
            index=i;
            break;
        }
    }
    /*O indexi explorerCrew ve minerCrew arraylerinde bakıp rName'e eşit olup olmadığına bakıyorum.
    Bu sayede robotun exp veya mnr olduğunu bulmuş oluyorum. Daha sonra eğer bu robot arraydeki tek robot değilse
    yani size birden büyükse robotu deleteliyorum. */
    if(index+1<=explorerCrewSize){
        if(ExplorerCrew[index]->getName()==rName && explorerCrewSize>1){
       for(int j=index;j<explorerCrewSize-1;j++){
           *ExplorerCrew[j] = *ExplorerCrew[j+1];
       }
       explorerCrewSize--;
        delete ExplorerCrew[explorerCrewSize];
        ExplorerCrew[explorerCrewSize]=new Explorer("x",5.5,5);Robot::decrementID();//I assigned explorer object with random values because after I deleted the last, it will try to delete again in the destructor
        
    }

    }
     if(index+1<=minerCrewSize){//index+1 kaçıncı robot olduğuna denk geliyor seg fault vermemesi adına sadece sizedan küçükse arrayi kontrol etmesini istiyorum.
        if(MinerCrew[index]->getName()==rName && minerCrewSize>1){
       for(int j=index;j<minerCrewSize-1;j++){
           *MinerCrew[j] = *MinerCrew[j+1];
       }
        minerCrewSize--;
        delete MinerCrew[minerCrewSize];
        MinerCrew[minerCrewSize]=new Miner("x",5.5,5);Robot::decrementID();//I assigned explorer object with random values because after I deleted the last, it will try to delete again in the destructor
        
    }

    }
    
};


void Crew::updateDurability(){
    if(explorerCrewSize!=0){
        cout<<"Explorer durability is being updated"<<endl;
    }

    for (int i=0;i<explorerCrewSize;i++){
        if(ExplorerCrew[i]->getDurability()!=0){//if durability is not zero decrement durability
            ExplorerCrew[i]->decrementDurability();
            
            if( ExplorerCrew[i]->getDurability()==0){//if durability is zero 
                cout<<ExplorerCrew[i]->getName() <<"'s durability=0"<<endl;
                this->operator-=(ExplorerCrew[i]->getName()); //delete robot
            }
        }

        if(explorerCrewSize==1 && ExplorerCrew[i]->getDurability()==0){ //if explorer is the only robot and its durability is zero
            ExplorerCrew[i]->setCanMove(false);
        }
    }
    if(explorerCrewSize!=0){
        cout<<"Miner durability is being updated"<<endl;
    }
    for (int i=0;i<minerCrewSize;i++){
       
        if(MinerCrew[i]->getDurability()!=0){
            MinerCrew[i]->decrementDurability();
            
            if( MinerCrew[i]->getDurability()==0){
                cout<<MinerCrew[i]->getName() <<"'s durability=0"<<endl;
                this->operator-=(MinerCrew[i]->getName());
            } 
        }
        if(minerCrewSize==1 && MinerCrew[i]->getDurability()==0){
            MinerCrew[i]->setCanMove(false);
        }  
    } 
}

const void Crew::showInfo()const{
    cout<<"explorerCrew Size:"<<explorerCrewSize<<endl;
    cout<<"minerCrew Size:"<<minerCrewSize<<endl;
    for (int i=0;i<explorerCrewSize;i++){
        ExplorerCrew[i]->showInfo();
    }

    for (int i=0;i<minerCrewSize;i++){
        MinerCrew[i]->showInfo();
    }
    cout<<"Total manufacture cost: " << this->crewManufactureCost<<endl;
    cout<<"Total maintenance cost: " << this->crewMaintenanceCost<<endl;
}

Crew::~Crew(){
    
    for (int i = 0; i<maxExplorers; i++) {delete ExplorerCrew[i];}
    delete [] ExplorerCrew;
    
    for (int i = 0; i<maxMiners; i++) {delete MinerCrew[i];}
    delete [] MinerCrew;
};
/*
****************
END: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/
CommandCenter::CommandCenter(const int neededSelenium, const float searchArea, const int seleniumWorth){
    this->neededSelenium=neededSelenium;
    this->searchArea=searchArea;
    this->seleniumWorth=seleniumWorth;
    this->profit=0;
    this->turnCount=1;
}

bool CommandCenter::isGameEnded(){
    
    if(Explorer::totalExploredArea>=this->searchArea){
        
        int total=Miner::totalGatheredSelenium;

        cout<<"Area has been fully explored."<<endl;
        cout<<"Aim: "<<this->neededSelenium<<" selenium."<<endl;
        cout<<"Collected: "<<total<<endl;

        if(this->profit>0 && this->neededSelenium<=total){
            
            cout<<"Congrats!"<<endl;
        }
        else{
            cout<<"Mission Failed!"<<endl;
        }
        return true;
    }
    return false;
}

void CommandCenter::calculateProfit(Crew& varCrew){
    this->profit=this->seleniumWorth*Miner::totalGatheredSelenium-varCrew.crewMaintenanceCost-varCrew.crewManufactureCost;
    cout<<"Profit:"<<this->profit<<endl;
    cout<<"Expenses:"<<varCrew.crewMaintenanceCost+varCrew.crewManufactureCost<<endl;
    cout<<"Selenium Revenue:"<<this->seleniumWorth*Miner::totalGatheredSelenium<<endl;
}

void CommandCenter::operator++(){
    this->turnCount++;
}

const void CommandCenter::showInfo()const{
    cout<<"Current turn: "<<this->turnCount<<endl;
    cout<<"Aim: "<<this->neededSelenium<<" selenium."<<endl;
    cout<<"Collected: "<<Miner::totalGatheredSelenium<<endl;
    cout<<"Total Search Area: "<<this->searchArea<<endl;
    cout<<"Explored Area: "<<Explorer::totalExploredArea<<endl;
    cout<<"Currently, there are "<<Explorer::totalNumberOfSeleniumArea<<" area/s that include selenium."<<endl;

    if(Explorer::totalNumberOfSeleniumArea!=0){
        cout<<"Mine these areas if miners have not finished their turn! If you cannot cope with mining, you can always add new miners!"<<endl;
    }
}
/*
****************
END: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/
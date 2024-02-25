 //--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------/

#include <iostream>
using namespace std;
#include "Robot.h"


/*
****************
BEGIN: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/
int Robot::unqID=1;

Robot::Robot( const string& RobotType, float speed, int durability, int manufactureCost, float maintenanceCost){
    this->RobotType=RobotType;
    this->speed=speed;
    this->durability=durability;
    this->manufactureCost=manufactureCost;
    this->maintenanceCost=maintenanceCost;
    this->canMove=true;
    if(RobotType=="explorer"){
        string str= to_string(unqID);//turning unqID to string
        RobotName="exp-"+str;
    }
    else if(RobotType=="miner"){
        string str= to_string(unqID);
        RobotName="mnr-"+str;
    }
    unqID++;
}

void Robot::operator=(const Robot& r){
    unqID=r.unqID;
	RobotName=r.RobotName;
	RobotType=r.RobotType;
	speed=r.speed;
	durability=r.durability;
	manufactureCost=r.manufactureCost;
	maintenanceCost=r.maintenanceCost;
	canMove=r.canMove;
};

const void Robot::showInfo()const{
    cout<<"Name: "<< this->RobotName<<endl;
    cout<<"Type: "<<this->RobotType<<endl;
    cout<<"Speed: "<<this->speed<<endl;
    cout<<"Durability: "<<this->durability<<endl;
    cout<<"ManufactureCost: "<<this->manufactureCost<<endl;
    cout<<"MaintenanceCost: "<<this->maintenanceCost<<endl;
    cout<<"Can Move: "<<this->canMove<<endl;

}
/*
****************
END: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/

float Explorer::totalExploredArea=0;
int Explorer::totalNumberOfSeleniumArea=0;

Explorer::Explorer( const string& expType, float expSpeed, int expDurability) : Robot( expType, expSpeed, expDurability,3000, 450.0/expSpeed){
	this->exploredArea=0;
    this->detectedSelenium=false;
}

void Explorer::explore(){
    int num=rand()%101;

    if(num>=40){
        detectedSelenium=true;
        totalNumberOfSeleniumArea++;
    }
    else{
        detectedSelenium=false;
    }
    totalExploredArea+=1500;
    exploredArea=1500;
    
}

const void Explorer::showInfo()const{
    Robot::showInfo();
    cout<<"explored area: "<<this->exploredArea<<endl;
}

bool Explorer::move(){
    
    return this->getCanMove();
}


void Explorer::operator=(const Explorer& e ){
    Robot::operator=(e);
    this->exploredArea=e.exploredArea;
    this->detectedSelenium=e.detectedSelenium;
}


/*
****************
END: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: MINER CLASS FUNCTION DECLARATIONS 
****************
*/
int Miner::totalGatheredSelenium=0;

Miner::Miner(const string& mnrType, float mnrSpeed, int mnrDurability ): Robot(mnrType, mnrSpeed, mnrDurability, 5000, 750/mnrSpeed){
    this->gatheredSelenium=0;
}

bool Miner::move(){
    
    if(Explorer::totalNumberOfSeleniumArea!=0 && this->getCanMove()==true){
        return true;
    }
    else{
        return false;
    }
   
}

void Miner::mine(){
    
    int amount=(rand()%91);
    amount=amount+10;
    amount=amount*5;
    gatheredSelenium=amount;
    totalGatheredSelenium+=amount;
    Explorer::totalNumberOfSeleniumArea--;
    
}

const void Miner::showInfo()const{
    Robot::showInfo();
    cout<<"# of gathered selenium: "<<this->gatheredSelenium<<endl;
}

void Miner::operator=(const Miner& m){
    Robot::operator=(m);
    this->gatheredSelenium=m.gatheredSelenium;

}

/*
****************
END: MINER CLASS FUNCTION DECLARATIONS 
****************
*/


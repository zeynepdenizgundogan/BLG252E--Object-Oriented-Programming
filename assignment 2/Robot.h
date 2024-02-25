//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

/*Hocam bazen calicoda build etmiyor. --timeout 10 ekleyerek bakabilirsiniz. */
#include <iostream>
#ifndef _H
#define _H
using namespace std;
class Robot {
	private:
		static int unqID;
		string RobotName;
		string RobotType;
		float speed; 
		int durability; 
		int manufactureCost; 
		float maintenanceCost;
		bool canMove;
	
	public:
	Robot(const string& , float, int, int, float);
	
	const int getUnqID()const;
	const string getName()const{return this->RobotName;};
	const string getRobotType()const{return this->RobotType;};
	const float getSpeed()const{return this->speed;};
	const int getDurability()const{return this->durability;};
	const int getManufactureCost()const{return this->manufactureCost;};
	const float getMaintenanceCost()const{return this->maintenanceCost;};
	static void decrementID(){unqID--;};
	void operator=(const Robot& );  
	const void showInfo()const;
	const bool getCanMove()const{return this->canMove;};
	void setCanMove(bool condition){this->canMove=condition;};
	void decrementDurability(){this->durability--;};
		           
}; 

class Explorer: public Robot{
	friend class Miner;
	friend class CommandCenter;
	private:
		static float totalExploredArea;
		static int totalNumberOfSeleniumArea;
		float exploredArea;
		bool detectedSelenium;
		
		
	public:
	Explorer(const string& , float, int);
	bool move();
	void explore();
	void operator=(const Explorer& );
	const void showInfo()const;
		
};

class Miner: public Robot{
	friend class CommandCenter;
	private:
		static int totalGatheredSelenium;
		int gatheredSelenium;

		
	public:
	Miner( const string&, float, int);
	
	bool move();
	void mine();
	const void showInfo()const;
	void operator=(const Miner& );
	void setGatheredSelenium(){this->gatheredSelenium=0;}
	const int getTotalGatheredSelenium()const{return this->totalGatheredSelenium;};
	const int getGatheredSelenium()const{return this->gatheredSelenium;};

		


};


#endif
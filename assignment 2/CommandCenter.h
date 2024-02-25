#include <iostream>
#include "Robot.h"
using namespace std;
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382

/*Hocam bazen calicoda build etmiyor. --timeout 10 ekleyerek bakabilirsiniz. */
class Crew{
	friend class CommandCenter;
	private:
		int maxExplorers;
		int maxMiners;
		int crewManufactureCost;
		float crewMaintenanceCost;
		int explorerCrewSize;
		int minerCrewSize;
		Explorer **ExplorerCrew;
		Miner **MinerCrew;
		
	public:
	Crew(int, int, int, int);
	Robot* manufactureRobot();
	Robot* manufactureRobot(string);
	void initMovement();
	
	void updateDurability();
	void operator+=( Robot* );
	void operator-=(const string& );

	const void showInfo()const;
	~Crew();
	const int getExplorerCrewSize()const{return this->explorerCrewSize;};
	const int getMinerCrewSize()const{return this->minerCrewSize;};
	void setCrewMaintenanceCost(float cost){this->crewMaintenanceCost=cost;};
	const float getCrewMaintenanceCost()const{return this->crewMaintenanceCost;};
	Miner** getMiners(){return this->MinerCrew;};
	Explorer** getExplorers(){return this->ExplorerCrew;};
};

class CommandCenter{
	private:
		int neededSelenium;
		float searchArea;
		int seleniumWorth;
		int turnCount;
		float totalCrewMaintenanceCost;
		float profit;
	public:
		CommandCenter(const int,const float,const int );
		bool isGameEnded();
		void calculateProfit(Crew&);
		void operator++();
		const void showInfo()const;

};




//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <vector>
//Hocam calico komutunu çalıştırırken timeout vererek çalıştırabilir misiniz? Diğer türlü bazen 100 bazen 0 veriyor.
class StatisticalDistribution{
    protected:
        double mean;
    public:
        const double get_mean()const{return this->mean;};
        virtual std::vector<double> sample(int, int)=0; 
        std::vector<double> calculate_confidence_interval(std::vector<double>, int, double);
        double calculate_mean(std::vector<double>, int);
        double calculate_std(std::vector<double>, int, double);     
};

class NormalDistribution : public StatisticalDistribution{
    private:
        double stddev;
    
    public:
        NormalDistribution();
        std::vector<double> sample(int,int);

};

class UniformDistribution : public StatisticalDistribution{
    private:
        double a;
        double b;
    
    public:
        UniformDistribution();
        std::vector<double> sample(int,int);
};

class ExponentialDistribution : public StatisticalDistribution{
    private:
        double lambda;

    public:
        ExponentialDistribution();
        std::vector<double> sample(int,int);
};

#endif
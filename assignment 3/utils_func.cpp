//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"

StatisticalDistribution* choose_function(int function){
    if(function == 0){
        NormalDistribution* normal = new NormalDistribution();
        return normal;}
    if(function==1){
        UniformDistribution* uniform = new UniformDistribution();
        return uniform;}
    if(function==2){
        ExponentialDistribution* exponential = new ExponentialDistribution();
        return exponential;
    }
    throw "Unidentified distribution function!";
}

double many_trials(StatisticalDistribution* dist, std::vector<double> random_sample , double t_value, int trials, int sample_size, int seed_value){
    std::vector<double> sample;
    std::vector<double> intervalVec;
    int success=0;
    double precision=0.0;
    for (int i=0; i<trials; i++){
        double mean=dist->get_mean();
        
        sample=dist->sample(sample_size, seed_value);
        intervalVec=dist->calculate_confidence_interval(sample, sample_size, t_value);
       
        if(intervalVec[0]<=mean && intervalVec[2]>=mean){
            success++;
        }
        seed_value++;

    }
    precision=(success*1.0)/trials;
    return precision;
}
 
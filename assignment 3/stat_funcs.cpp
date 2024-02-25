//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname:Zeynep Deniz Gündoğan
//---Student Number:040190382
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//using namespace std;

//Hocam calico komutunu çalıştırırken timeout vererek çalıştırabilir misiniz? Diğer türlü bazen 100 bazen 0 veriyor.
#include "statistics.h"
#include <random>
#include <iostream>

NormalDistribution::NormalDistribution(){
    this->mean=0.0;
    this->stddev=1.0;
}

UniformDistribution::UniformDistribution(){
    this->mean=0.0;
    this->a=-1.0;
    this->b=1.0;
}

ExponentialDistribution::ExponentialDistribution(){
    this->mean=1.0;
    this->lambda=1.0;
}

double StatisticalDistribution::calculate_mean(std::vector <double> sampleVec, int sampleSize){
    double sampleMean=0.0;
    double addition=0.0;
    for(int i=0; i<sampleSize;i++){
        
        addition = sampleVec[i] + addition;
    }

    sampleMean=addition/sampleSize; //second element
    return sampleMean;

}

double StatisticalDistribution::calculate_std(std::vector <double> sampleVec, int sampleSize, double sampleMean){
    double staDeviation=0.0;
    double tempAdd=0.0;
    for(int i=0; i<sampleSize;i++){
        double temp=0.0;
        temp = sampleVec[i] - sampleMean;
        temp=temp*temp;
        tempAdd = temp + tempAdd;
    }
    staDeviation=sqrt(tempAdd/(sampleSize-1));
    return staDeviation;
}

std::vector <double> StatisticalDistribution::calculate_confidence_interval(std::vector <double> randomSample, int sampleSize, double tValue){
    
    double staDeviation=0.0;
    double lower_bound=0.0;
    double upper_bound=0.0;

    std::vector<double> finalVector;
    double sampleMean=calculate_mean(randomSample, sampleSize);

    staDeviation=calculate_std(randomSample, sampleSize, sampleMean);

    lower_bound=sampleMean-(tValue*staDeviation/std::sqrt(sampleSize));
    upper_bound=sampleMean+(tValue*staDeviation/std::sqrt(sampleSize));

    finalVector.push_back(lower_bound);
    finalVector.push_back(sampleMean);
    finalVector.push_back(upper_bound);

    return finalVector;
}

std::vector<double> NormalDistribution::sample(int sample_size, int seed_value){
    double number=0.0;
    std::vector<double> normalSample;

    std::default_random_engine generator;
    generator.seed(seed_value);
    std::normal_distribution<double> distribution(mean, stddev);
    for (int i = 0; i<sample_size; i++){
        number = distribution(generator);
        normalSample.push_back(number);
    }
    return normalSample;
};

std::vector<double> UniformDistribution::sample(int sampleSize, int seedValue){
    double number=0.0;
    std::vector<double> uniformSample;
    std :: default_random_engine generator ;
     generator . seed ( seedValue );
    std :: uniform_real_distribution < double > distribution (a, b);

    
    for(int i=0; i<sampleSize;i++){
        
        number = distribution ( generator );
        uniformSample.push_back(number);

    }
    return uniformSample;
    
}

std::vector<double> ExponentialDistribution::sample(int sampleSize, int seedValue){
    double number=0.0;
    std::vector<double> exponentialSample;
    std :: default_random_engine generator ;
    generator . seed ( seedValue );
    std :: exponential_distribution <double > distribution ( lambda );
    for(int i=0; i<sampleSize;i++){
        
        number = distribution ( generator );
        exponentialSample.push_back(number);
    }
    return exponentialSample;
}
#pragma once
#include <ctime>
#include <random>
#include <cmath>

namespace util {

    /*
        @returns random floating point number in distribution
    */        
    double randomF(double lower_bound, double upper_bound);     
    /*
        @returns random integer in distribution
    */     
    int randomI(int lower_bound, int upper_bound);

    /*
        @returns sigmoid of x
    */
    double sigmoid(double x);
}
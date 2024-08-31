#pragma once
#include <ctime>
#include <random>
#include <cmath>

namespace util {

    template<class T>
    T random(T lower_bound, T upper_bound) {
        // Create a static random number generator
        static std::random_device rd;  
        static std::mt19937 gen(rd()); 

        // Create a uniform distribution in the specified range
        std::uniform_real_distribution<T> dis(lower_bound, upper_bound);

        // Generate and return the random float
        return dis(gen);
    }


    double sigmoid(double x) {
        return 1 / (1 + exp(-x));
    }

}
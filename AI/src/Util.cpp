#include "Util.hpp"

  /*
        @returns random floating point number in distribution
    */        
    double util::randomF(double lower_bound, double upper_bound) {
        // Create a static random number generator
        static std::random_device rd;  
        static std::mt19937 gen(rd()); 
        // Create a uniform distribution in the specified range
        std::uniform_real_distribution<double> dis(lower_bound, upper_bound);
        // Generate and return the random float
        return dis(gen);        
    }

    /*
        @returns random integer in distribution
    */     
    int util::randomI(int lower_bound, int upper_bound) {
        // Create a static random number generator
        static std::random_device rd;  
        static std::mt19937 gen(rd()); 

        std::uniform_int_distribution<int> dis(lower_bound, upper_bound);
        return dis(gen);
    }


    /*
        @returns sigmoid of x
    */
    double util::sigmoid(double x) {
        return 1 / (1 + exp(-x));
    }
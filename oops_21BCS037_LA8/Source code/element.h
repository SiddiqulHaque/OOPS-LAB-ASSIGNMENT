#include <bits/stdc++.h>
using namespace std;

double rand_gen(){
    double lower_bound = 0, upper_bound = 100;
    uniform_real_distribution<double> unif(lower_bound, upper_bound);
    default_random_engine re;
    return unif(re);
}

class Element{
    public:
        virtual void print() = 0;
        virtual double norm() = 0;
};
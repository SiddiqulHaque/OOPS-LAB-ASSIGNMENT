#include <bits/stdc++.h>
using namespace std;

class PointN : public Element{
        double * pN;
        int _n;
    public:
        PointN();
        PointN(double *arr, int n);
        PointN(int n);
        ~PointN();
        void print();
        double norm();
        void setRandom();

};


PointN :: PointN(){
    // cout<<"PointN: Default Constructior";
    pN = new double[2];
    _n = 2;
}


PointN :: PointN(double * arr, int n){
    // cout<<"PointN: Parameterized Constructior (arr, n) ";
    pN = new double[n];
    _n = n;
    for(int i=0; i<n; i++){
        pN[i] = arr[i];
    }
}


PointN :: PointN(int n){
    // cout<<"PointN: Parameterized Constructior (n) ";
    pN = new double[n];
    _n = n;
}

PointN :: ~PointN(){
    // cout<<"PointN: Destructior (n) ";
    delete pN;
    pN = NULL;
    _n = 0;
}

void PointN :: setRandom(){

    for(int i=0; i<_n; i++){
        // double x = rand()%100;
        double x = rand_gen();

        pN[i] = x;
        // cout<<x<<" ";
    }
}

void PointN :: print (){

    for(int i=0; i<_n; i++){
        cout<<pN[i]<<" ";
    }

}

double PointN :: norm (){

    double dist = 0;
    for(int i=0; i<_n; i++){
        dist += pN[i]*pN[i];
    }

    return dist;

}
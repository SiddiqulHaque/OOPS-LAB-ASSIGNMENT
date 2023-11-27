#include <iostream>


class Vector : public Element{
    protected:
        double _i, _j, _k;
    public:
        Vector(){_i = 0; _j=0;}
        Vector(int i, int j){
            _i=i; _j = j;
        }
        void print();
        double norm();
};


void Vector :: print (){
    cout<<"i = "<<_i<<", j = "<<_j<<endl
        <<"Norm = "<<norm()<<endl;
}

double Vector :: norm (){
    double dist;
    dist =( _i*_i) + (_j *_j);
    return dist;
}
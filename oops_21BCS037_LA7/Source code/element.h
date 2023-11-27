

#include <bits/stdc++.h>

using namespace std;


class Element{
    public:
        virtual void print() =0;
};

class Vector : public Element{
    public:
        void print();
};

void Vector :: print (){
    cout<<"Vector Virtual function"<<endl;
}
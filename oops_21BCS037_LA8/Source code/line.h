#include <iostream>



class Line : public Element{
    private:
        int length;
        string name;
    
    public:
        Line (int l, string n){length = l; name = n;}
        Line (string n){name = n; length = 0;}
        Line (int l){length = l; name = "";}
        Line (){length = 0; name = "";}
        double norm();
        void print();


};


double Line :: norm (){

    double distance = 0;

    double L1 = length * length;

    // distance = sqrt (L1);
    distance = L1;

    return distance;
}

void Line :: print (){

    cout<<"Name = "<<name<<endl
        <<"Length = "<<length<<endl
        <<"Norm = "<<norm()<<endl;

}
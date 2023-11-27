#include <iostream>
#include <math.h>
using namespace std;

class Point {
    // Private Access Modifiers - By default
    double _x, _y; // Can be accessed within the scope of the class not outside

    public: // Public Access Modifiers
        // Member function can only be accessed by the object of that class.
        // Declaration of memeber functions
        void setCoords ( double x, double y);
        void printCoords ();
        double distFrom(Point &p);
        Point midPoint (Point &p);
        Point(); // Default Constructor;
        Point(double x, double y); // Parameterized Constructor
        Point(Point &p); // Copy constructor
        ~Point(); // Destructor
        static 
};
// Definition of memeber functions

Point :: Point (){} // default constructor

Point :: ~Point (){} // destructor

Point :: Point (double x, double y){
    _x = x;
    _y = y;
} // Parameterized constructor

// memeber functions 
void Point :: setCoords ( double x, double y){
    _x = x;
    _y = y;
} 

void Point :: printCoords (){
    cout<<_x<<","<<_y<<endl;
}

// 5. Memeber function accessing private member of all objects of this class
double Point :: distFrom(Point &p){
    
    double d;
    d = sqrt( pow( (_x-p._x), 2 ) + pow( (_y-p._y), 2 ) );
    
    return d;
    
}

Point Point :: midPoint (Point &p){
    
    Point nP;
    
    nP._x = (_x+p._x)/2;
    nP._y = (_y+p._y)/2;
    
    return nP;
    
}




int main(){

    Point p1(1,2);
    
    Point p2(3,4);
    
    cout<<p1.distFrom(p2)<<endl;
    
    Point p3;
    
    p3 = p1.midPoint(p2);
    
    p3.printCoords();

}

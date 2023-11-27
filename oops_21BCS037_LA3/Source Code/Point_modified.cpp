#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Point {
    // Private Access Modifiers - By default
    double _x, _y; // Can be accessed within the scope of the class not outside
    
    const int origin_x = 0;
    const int origin_y = 0;
    
    
    
    
    static int test; // memeory is allocated for static data memebers once they are defined even though no objects of that class have been instantiated. Verified using variable 'test'
    
    static int count, countTL, countTR, countBR, countBL; // declaration of static variable no memory is allocated here.
    
    
    // Private Memeber functions
    void decQuads();
    void incQuads(double x, double y);

    public: // Public Access Modifiers
        // Member function can only be accessed by the object of that class.
        // Declaration of memeber functions
        void setCoords ( double x, double y);
        void printCoords ();
        double distFrom(Point &p) const ; // const memeber func
        Point midPoint (Point &p); // Declaring a member function with the const keyword specifies that the function is a "read-only" function that doesn't modify the object for which it's called. A constant member function can't modify any non-static data members or call any member functions that aren't constant.
        Point(); // Default Constructor;
        Point(double x, double y); // Parameterized Constructor
        Point(Point &p); // Copy constructor
        ~Point(); // Destructor
        static int objInstances(); // static memeber function
        static void pointsIn2DQuadrants();
        void setQuads(double x, double y);
        static void printTest();
        
        void setGraph();
        void visualizeGraph();
        
};
// Definition of memeber functions

Point :: Point (){
    count++;
    _x = _y = 0;
    cout<<"constructor is called";
} // default constructor

Point :: ~Point (){
    count--;
    decQuads();
    cout<<"Destructor is called for "<<_x<<","<<_y<<endl;
} // destructor

Point :: Point (double x, double y){
    count++;
    setQuads(x, y);
    _x = x;
    _y = y;
} // Parameterized constructor

// memeber functions 
void Point :: setCoords ( double x, double y){
    setQuads(x, y);
    _x = x;
    _y = y;
} 

void Point :: printCoords (){
    cout<<_x<<","<<_y<<endl;
}

// 5. Memeber function accessing private member of all objects of this class
double Point :: distFrom(Point &p) const{ // const memeber because it can't change the data memeber of this object
    
    double d;
    d = sqrt( pow( (_x-p._x), 2 ) + pow( (_y-p._y), 2 ) );
    
    return d;
    
}

Point Point :: midPoint (Point &p){
    
    Point nP;
    
    nP._x = (_x+p._x)/2;
    nP._y = (_y+p._y)/2;
    
    setQuads(nP._x , nP._y);
    
    return nP;
    
}

// Static 

int Point :: test = 54;

void Point :: printTest (){
    cout<<test<<endl;
}

int Point :: count = 0; // definition of static variable. Memory is allocated here;

int Point :: objInstances (){
    return count;
}

// 2D quadrant
int Point :: countTR = 0; 
int Point :: countTL = 0;
int Point :: countBR = 0;
int Point :: countBL = 0;

void Point :: decQuads (){
    if( _x < 0 and _y > 0  ){
        countTL--;
    } else if( _x > 0 and _y > 0  ){
        countTR--;
    } else if( _x > 0 and _y < 0  ){
        countBR--;
    } else if( _x < 0 and _y < 0  ){
        countBL--;
    }
}

void Point :: incQuads (double x, double y){
    if( x < 0 and y > 0 ){
        countTL++;
    } else if( x > 0 and y > 0 ){
        countTR++;
    } else if( x > 0 and y < 0 ){
        countBR++;
    } else if( x > 0 and y > 0 ){
        countBL++;
    }
}

void Point :: setQuads (double x, double y){

    decQuads();
    incQuads(x, y);

}

void Point :: pointsIn2DQuadrants (){
    cout<<"countTL = "<<countTL<<endl;
    cout<<"countTR = "<<countTR<<endl;
    cout<<"countBR = "<<countBR<<endl;
    cout<<"countBL = "<<countBL<<endl;
}

// void Point :: setGraph(){
    
//     for(int i=0; i<10; i++){
//         for(int j=0; j<10; j++){
//             graph[i][j] = setCoords(i,j);
//         }
//     }
    
// }


// void Point :: visualizeGraph(){
    
//     for(int i=0; i<10; i++){
//         for(int j=0; j<10; j++){
//             cout<<"x= "<<graph[i][j]._x<<", y= "<<graph[i][j]._y<<endl;
//         }
//     }
    
// }


int main(){
    
    
    // Point :: printTest();

    Point p1(1,2);
    
    Point p2(-3,4);
    
    Point p3(-3,4);
    
    Point p;


    cout << "No of objects of Point class = "<< Point :: objInstances() << endl;
    Point :: pointsIn2DQuadrants();
}

#include <iostream>
#include "./point.h"
#include "./pointN.h"
#include "./line.h"
int main (){
    Point p (2,3);
    Line l (10, "L1");
    l.print();
    p.print();
    double arr[10];
    for(int i=0;i<10;i++){
        arr[i]=i;
    }
    PointN pn1(arr,10);
    // pn1.setRandom();
    pn1.print();
    return 0;
}
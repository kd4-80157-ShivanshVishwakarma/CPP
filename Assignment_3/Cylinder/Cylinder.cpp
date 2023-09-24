#include"./Cylinder.h"

    Cylinder::Cylinder(){
        this->radius=5.2;
        this->height=10.4;
    }
    Cylinder::Cylinder(double radius,double height):radius(radius),height(height){
        
    }
    double Cylinder::getRadius(){
        return this->radius;
    }
    void Cylinder::setRadius(double radius){
        this->radius=radius;
    }
    double Cylinder::getHeight(){
        return this->height;
    }
    void Cylinder::setHeight(double height){
        this->height=height;
    }
    double Cylinder::getVolume(){
        return (3.14*this->radius*this->radius*this->height);
    }
    void Cylinder::printVolume(){
        cout<<"Volume of Cylinder : "<<getVolume()<<endl;
    }
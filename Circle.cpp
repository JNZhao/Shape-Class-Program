#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Circle.h"

using namespace std;

Circle::Circle(string _name, string _colour, float _xcen, float _ycen, float _radius):Shape(_name, _colour, _xcen, _ycen){
    radius=_radius;
}

Circle::~Circle(){
    
}

void Circle::print() const{
    Shape::print();
    cout << "circle radius: " << radius << endl;
}

void Circle::scale(float scaleFac){
    radius *=scaleFac;
}

float Circle::computeArea() const{
    float area=pow(radius,2)*PI;
    return area;
}

float Circle::computePerimeter() const{
    float perimeter=2*PI*radius;
    return perimeter;
}

void Circle::draw (easygl* window) const {
  
   float xcen = getXcen();
   float ycen =getYcen();
   window->gl_setcolor(getColour());
   window->gl_fillarc(xcen, ycen, radius, 0, 360);
}

bool Circle::pointInside (float x, float y) const {
 
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();
   
   
   if(click.x <= radius && click.y <= radius)//distance from center point less than radius (inside the graph)
   {
       return true;
   }
   else 
   {
       return false;
   }
}





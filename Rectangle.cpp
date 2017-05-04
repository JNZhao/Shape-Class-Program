#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle (string _name, string _colour, float _xcen, float _ycen, float _width, float _height):Shape(_name,_colour,_xcen,_ycen){
    width=_width;
    height=_height;
    
}


Rectangle::~Rectangle(){
    
}

void Rectangle::print() const{
    Shape::print();   //base
    cout << "rectangle width: " << width << " height: " << height << endl;
    
}

void  Rectangle::scale(float scaleFac){
    width*=scaleFac;
    height*=scaleFac;
}

float Rectangle::computeArea() const{
    float area=abs(width*height);
    return area;
}

float Rectangle::computePerimeter()const{
    float perimeter=2*(width+height);
    return perimeter;
}

void Rectangle::draw(easygl* window) const{
    float leftSide, rightSide, topSide, bottomSide;
    leftSide=getXcen()-width/2;
    rightSide=getXcen()+width/2;
    topSide=getYcen()+height/2;
    bottomSide=getYcen()-height/2;
    
    window->gl_setcolor(getColour());
    window->gl_fillrect(leftSide,bottomSide,rightSide,topSide);
}

bool Rectangle::pointInside(float x, float y) const{
    t_point click;
    click.x=x-getXcen();
    click.y=y-getYcen();
    
    t_point vecToClick, vecOfSide;
    
    if(click.x >= -width / 2 && click.x <= width/2 && click.y >= - height / 2 && click.y <= height/2)//make sure the point inside the rectangle
        return true;
    else
        return false;
}

t_point Rectangle::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}




#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Polygon.h"

using namespace std;


Polygon::Polygon(string _name, string _colour, float _xcen, float _ycen, float _xcoords[1000], float _ycoords[1000], int _n):Shape(_name, _colour, _xcen, _ycen){
    n=_n;
    for(int i=0;i<n;i++){
        relVertex[i].x=_xcoords[i];
        relVertex[i].y=_ycoords[i];
    }
}


Polygon::~Polygon(){
    
}


void Polygon::print() const{
    Shape::print();
    cout<<"polygon";
    for(int i=0;i<n;i++){
        cout << " (" << relVertex[i].x+getXcen() << "," << relVertex[i].y+getYcen() << ")";
    }
    cout<<endl;
}

void Polygon::scale(float scaleFac){
    for(int i=0;i<n;i++){
        relVertex[i].x*=scaleFac;
        relVertex[i].y*=scaleFac;
    }
}

float Polygon::computeArea() const{
    int j=n-1;
    float area=0;
    for (int i = 0; i<n; i++) {
       area = area + ((relVertex[j].x+relVertex[i].x) * (relVertex[j].y-relVertex[i].y));
       j = i; 
   }
    return area/2;
}

float Polygon::computePerimeter () const {
   float perimeter = 0;
   float sideLength;
   int endIndex;
   t_point d;
   
   for (int i = 0; i < n; i++) {
      endIndex = (i + 1) % n;
      d = getVecBetweenPoints (relVertex[i], relVertex[endIndex]);
      sideLength = sqrt (d.x * d.x + d.y * d.y);
      perimeter += sideLength;
   }
   return perimeter;
}

void Polygon::draw (easygl* window) const {

   t_point *coords = new t_point[n];  
   for (int i = 0; i < n; i++) {
      coords[i].x = getXcen() + relVertex[i].x;
      coords[i].y = getYcen() + relVertex[i].y;
   }
   
   window->gl_setcolor(getColour());
   window->gl_fillpoly(coords, n);
   
   
}


bool Polygon::pointInside (float x, float y) const {
   
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();
   
  
   
   t_point vecOfSide;
   float distanceAlongVector, yDistance;
   int endIndex;
   int sidesToLeft = 0;
   
   for (int istart = 0; istart < n; istart++) {
      endIndex = (istart + 1) % n; 
      vecOfSide = getVecBetweenPoints (relVertex[istart], relVertex[endIndex]);
      yDistance = (click.y - relVertex[istart].y);
      if (vecOfSide.y != 0) {
          distanceAlongVector = yDistance / vecOfSide.y;
      }
      else if (yDistance == 0) {
          distanceAlongVector = 0;
      }
      else {
          distanceAlongVector = 1e10; 
      }
      
    
      if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
         float xIntersection = relVertex[istart].x + vecOfSide.x * distanceAlongVector;
         if (xIntersection <= click.x ) 
             sidesToLeft++;
      }
   }
   
   return (sidesToLeft == 1);
}


t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}



float Polygon::CrossProduct (t_point vec1, t_point vec2) const {
   return (vec1.x * vec2.y - vec1.y * vec2.x);
}
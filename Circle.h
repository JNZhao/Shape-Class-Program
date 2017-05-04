/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circ;e.h
 * Author: jiananzhao
 *
 * Created on November 30, 2016, 11:45 PM
 */

#ifndef CIRC_E_H
#define CIRC_E_H

#include "Shape.h"
#include "easygl.h"

class Circle : public Shape {
private:
   
    float radius;
   
public:
   Circle (string _name, string _colour, float _xcen, float _ycen,
            float _radius);
   
   // virtual keyword is optional in all the function declarations below, since
   // the base class Shape already declared them virtual. But it is good 
   // practice to repeat it again here, for clarity.
   virtual ~Circle();
   
   
   virtual void print () const;
   virtual void scale (float scaleFac);
   virtual float computeArea () const;
   virtual float computePerimeter () const;
   virtual void draw (easygl* window) const;
   virtual bool pointInside (float x, float y) const;
};

#endif /* CIRC_E_H */


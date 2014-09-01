
#pragma once
#include "Point2D.h"
/*!
    * Getter for *this->x* value 
    */
template<typename C>
C Point2D<C>:: getX() 
{
    return this->x;
}
/*!
    * Getter for *this->y* value 
    */
template<typename C>
C Point2D<C>::getY() 
{
    return this->y;
}

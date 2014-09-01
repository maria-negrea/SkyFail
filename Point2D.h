#pragma once

template<typename C>
class Point2D {
    private:
        /*!
        * Value for coordinate on the OX axis 
        */
        C x;
        /*!
        * Value for coordinate on the OY axis 
        */
        C y;
    public:
        Point2D(C X, C Y) {
            this->x = X;
            this->y = Y;
        }
        
        C getX();
        C getY();

        ~Point2D() {

        }
};
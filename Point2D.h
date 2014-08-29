#pragma once

template<typename C>
class Point2D {
    private:
        C x;
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
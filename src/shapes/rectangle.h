//
// Created by BROUILLE Théo on 20/02/2022.
//

#ifndef SVG_CREATOR_RECTANGLE_H
#define SVG_CREATOR_RECTANGLE_H


#include "../shape.h"

class Rectangle: public Shape {
private:
    int width, height;

public:
    Rectangle(
        const int x,
        const int y,
        const int width,
        const int height,
        std::string stroke,
        std::string fill
    );

    std::string getSVGTag();
};


#endif //SVG_CREATOR_RECTANGLE_H

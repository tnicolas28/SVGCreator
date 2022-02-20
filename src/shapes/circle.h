//
// Created by BROUILLE Théo on 20/02/2022.
//

#ifndef SVG_CREATOR_CIRCLE_H
#define SVG_CREATOR_CIRCLE_H


#include "../shape.h"

class Circle: public Shape {
private:
    int r;

public:
    Circle(
        const int x,
        const int y,
        const int r
    );

    std::string getSVGTag();
};


#endif //SVG_CREATOR_CIRCLE_H

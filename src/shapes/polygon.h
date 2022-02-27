//
// Created by Salayna Doukoure on 27/02/2022.
//

#ifndef SVG_CREATOR_POLYGON_H
#define SVG_CREATOR_POLYGON_H


#include <vector>
#include "../shape.h"
#include "point.h"

class Polygon: public Shape{
private:
    std::vector<point> points;
public:
    Polygon(
            const int x,
            const int y,
            std::vector<point> point);

    std::string getSVGTag();
};


#endif //SVG_CREATOR_POLYGON_H

//
// Created by Salayna Doukoure on 27/02/2022.
//

#include "polygon.h"

Polygon::Polygon(const int x, const int y, std::vector<point> points ) : Shape(x, y, "polygon") {
    this->points = points;
}

std::string Polygon::getSVGTag() {
    printf("start\n");
    std::string tag = "<" + this->svgTagName
                       + " points= '";
    for (int i = 0; i<points.size(); i++ ){
        printf("adding a point\n");
        tag += std::to_string(this->points[i].x) +','+ std::to_string(this->points[i].y) + " ";
    }
    tag+= "' stroke= 'white'/>";
    return tag;
}
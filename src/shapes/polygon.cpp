//
// Created by Salayna Doukoure on 27/02/2022.
//

#include "polygon.h"

Polygon::Polygon(const int x, const int y, std::string stroke, std::string fill, std::vector<point> points ) : Shape(x, y, "polygon", fill, stroke) {
    this->fill = fill;
}

std::string Polygon::getSVGTag() {
    std::string tag = "<" + this->svgTagName
                       + " points= '";
    for (int i = 0; i<points.size(); i++ ){
        tag += std::to_string(this->points[i].x) +','+ std::to_string(this->points[i].y) + " ";
    }
    tag+= "' stroke= '"
            + this->stroke
            + "'"
            + " fill= '"
            + this->fill
            + "'/>";
    return tag;
}


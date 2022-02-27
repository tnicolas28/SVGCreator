//
// Created by BROUILLE Théo on 20/02/2022.
//

#include "circle.h"

Circle::Circle(const int x, const int y, const int r): Shape(x, y, "circle") {
    this->r = r;
}

std::string Circle::getSVGTag() {
    return "<" + this->svgTagName
           + " cx='" + std::to_string(this->x)
           + "' cy='" + std::to_string(this->y)
           + "' r='" + std::to_string(this->r) + "' />";
}

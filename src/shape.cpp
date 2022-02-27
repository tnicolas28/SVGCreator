//
// Created by BROUILLE Théo on 20/02/2022.
//

#include "shape.h"

Shape::Shape(const int x, const int y, const std::string svgTagName, std::string stroke, std::string fill) {
    this->x = x;
    this->y = y;
    this->svgTagName = svgTagName;
    this->stroke = stroke;
    this->fill = fill;
}

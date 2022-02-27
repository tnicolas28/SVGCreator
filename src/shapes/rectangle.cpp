//
// Created by BROUILLE Théo on 20/02/2022.
//

#include "rectangle.h"

Rectangle::Rectangle(const int x, const int y, const int width, const int height, std::string  stroke, std::string fill): Shape(x, y, "rect", stroke, fill) {
    this->width = width;
    this->height = height;
}

std::string Rectangle::getSVGTag() {
    return "<" + this->svgTagName
            + " x='" + std::to_string(this->x)
            + "' y='" + std::to_string(this->y)
            + "' width='" + std::to_string(this->width)
            + "' height='" + std::to_string(this->height)+ "' "
            + "stroke='" + this->stroke+"' "
            + "fill='" + this->fill+
            + "' />";
}

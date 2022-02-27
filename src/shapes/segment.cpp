//
// Created by Salayna Doukoure on 27/02/2022.
//

#include "segment.h"

Segment::Segment(int x, int y, int start, int end): Shape(x, y, "path"){
    this->start = start;
    this->end = end;
}

std::string Segment::getSVGTag() {
    return "<" + this->svgTagName
           + " d=L'" + std::to_string(this->x)
           + "' />";
}
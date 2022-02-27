//
// Created by Salayna Doukoure on 27/02/2022.
//

#include "segment.h"

Segment::Segment(int x, int y, point start, point end, std::string  stroke, std::string fill): Shape(x, y, "path", stroke, fill){
    this->start = start;
    this->end = end;
}

std::string Segment::getSVGTag() {
    return "<" + this->svgTagName
           + " d='M "+ std::to_string(this->start.x)
           + " " + std::to_string(this->start.y)
           + " L " + std::to_string(this->end.x)
           + " " + std::to_string(this->end.y)
           + "' stroke='" + this->stroke + "'/>";
}

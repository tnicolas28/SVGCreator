//
// Created by Salayna Doukoure on 27/02/2022.
//

#ifndef SVG_CREATOR_SEGMENT_H
#define SVG_CREATOR_SEGMENT_H


#include "../shape.h"
#include "point.h"

class Segment: public Shape{
private:
    point start;
    point end;
public:
    Segment(
            int x,
            int y,
            point start,
            point end
            );

    std::string getSVGTag();
};


#endif //SVG_CREATOR_SEGMENT_H

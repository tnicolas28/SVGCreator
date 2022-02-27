//
// Created by Salayna Doukoure on 27/02/2022.
//

#ifndef SVG_CREATOR_SEGMENT_H
#define SVG_CREATOR_SEGMENT_H


#include "../shape.h"

class Segment: public Shape{
private:
    int start, end;
public:
    Segment(
            int x,
            int y,
            int start,
            int end
            );

    std::string getSVGTag();
};


#endif //SVG_CREATOR_SEGMENT_H

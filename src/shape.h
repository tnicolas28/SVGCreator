//
// Created by BROUILLE Théo on 20/02/2022.
//

#ifndef SVG_CREATOR_SHAPE_H
#define SVG_CREATOR_SHAPE_H


#include <string>

class Shape {
protected:
    int x, y;
    std::string svgTagName;

    Shape(
        const int x,
        const int y,
        const std::string svgTagName
    );

public:
    virtual std::string getSVGTag() = 0;
};


#endif //SVG_CREATOR_SHAPE_H

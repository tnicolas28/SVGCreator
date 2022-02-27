#include <iostream>
#include <vector>
#include <fstream>

#include "src/helpers/Prompter.h"
#include "src/shapes/rectangle.h"
#include "src/shapes/circle.h"
#include "src/shapes/point.h"
#include "src/shapes/segment.h"
#include "src/shapes/polygon.h"

int main() {
    // Prompt user input
    std::vector<std::string> shapes;

    shapes.push_back("Rectangle");
    shapes.push_back("Circle");
    shapes.push_back("Polygon");
    shapes.push_back("Segment");

    std::vector<std::string> colors;
    colors.push_back("transparent");
    colors.push_back("red");
    colors.push_back("purple");
    colors.push_back("green");

    for(int i = 1; i <= shapes.size() ; i++){
        std::cout << "  " <<i << ". " << shapes[i - 1] << std::endl;
    }

    int userChoice;
    std::string fileName;

    do {
        userChoice = Prompter::promptInt("Choose the shape you want to draw");

        if (!(1 <= userChoice && userChoice <= 4)) {
            std::cout << "Please enter a valid choice" << std::endl;
        }
    } while(!(1 <= userChoice && userChoice <= 4));

    std::cout << "You decided to draw : " << shapes[userChoice - 1] << std::endl;

    // Write to SVG

    std::ofstream file;
    file.open("new_svg.svg", std::ofstream::out);

    if (!file) {
        std::cout << "Unable to create a new file" << std::endl;
        return 1;
    }

    file << "<svg width='100' height='100' xmlns='http://www.w3.org/2000/svg'>" << "\n";

    Shape* shape;

    switch(userChoice) {
        case 1: {
            int x = Prompter::promptInt("Enter the x of the rectangle");
            int y = Prompter::promptInt("Enter the y of the rectangle");
            int width = Prompter::promptInt("Enter the width of the rectangle");
            int height = Prompter::promptInt("Enter the height of the rectangle");
            for(int i = 1; i <= colors.size() ; i++){
                std::cout << "  " <<i << ". " << colors[i - 1] << std::endl;
            }
            std::string fill;
            std::string stroke;
            int strokeChoice = Prompter::promptInt("Choose the color of the stroke");
            stroke = colors[strokeChoice - 1];
            int colorChoice = Prompter::promptInt("Choose the filling color");
            fill = colors[colorChoice - 1];
            shape = new Rectangle(x, y, width, height, stroke, fill);
            break;
        }
        case 2: {
            int x = Prompter::promptInt("Enter the x of the circle");
            int y = Prompter::promptInt("Enter the y of the circle");
            int r = Prompter::promptInt("Enter the radius of the circle");
            std::string fill;
            std::string stroke;
            int strokeChoice = Prompter::promptInt("Choose the color of the stroke");
            stroke = colors[strokeChoice - 1];
            int colorChoice = Prompter::promptInt("Choose the filling color");
            fill = colors[colorChoice - 1];
            shape = new Circle(x, y, r, stroke, fill);
            break;
        }
        case 3: {
            std::string fill;
            std::string stroke;
            std::vector<point> points;
            std::string command = "continue";
            while (command == "continue"){
                int x = Prompter::promptInt("Enter the x of the point");
                int y = Prompter::promptInt("Enter the y of the point");
                point p;
                p.x = x;
                p.y = y;
                points.push_back(p);
                char shouldStop = Prompter::promptChar("Add another point ? (Y/N)");
                if (shouldStop == 'Y' || shouldStop == 'y') continue;
                command = "stop";
            }
            for(int i = 1; i <= colors.size() ; i++){
                std::cout << "  " <<i << ". " << colors[i - 1] << std::endl;
            }
            int strokeChoice = Prompter::promptInt("Choose the color of the stroke");
            stroke = colors[strokeChoice - 1];
            int colorChoice = Prompter::promptInt("Choose the filling color");
            fill = colors[colorChoice - 1];
            shape = new Polygon(0,0,stroke,fill,points);
            break;
        }
        case 4:{
            int x1 = Prompter::promptInt("Enter the x of the start of the line");
            int y1 = Prompter::promptInt("Enter the y of the start of the line");
            int x2 = Prompter::promptInt("Enter the x of the end of the line");
            int y2 = Prompter::promptInt("Enter the y of the end of the line");
            point p1;
            point p2;
            p1.x = x1;
            p1.y = y1;
            p2.x = x2;
            p2.y = y2;
            std::string fill;
            std::string stroke;
            int strokeChoice = Prompter::promptInt("Choose the color of the stroke");
            stroke = colors[strokeChoice - 1];
            int colorChoice = Prompter::promptInt("Choose the filling color");
            fill = colors[colorChoice - 1];
            shape = new Segment(0,0, p1, p2, stroke, fill);
            break;
        }
        default:
            break;
    }

    file << shape->getSVGTag() << "\n";

    file << "</svg>";
    file.close();

    return 0;
}

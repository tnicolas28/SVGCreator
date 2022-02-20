#include <iostream>
#include <vector>
#include <fstream>

#include "src/helpers/Prompter.h"
#include "src/shapes/rectangle.h"
#include "src/shapes/circle.h"

int main() {
    // Prompt user input
    std::vector<std::string> shapes;

    shapes.push_back("Rectangle");
    shapes.push_back("Circle");
    shapes.push_back("Polygon");
    shapes.push_back("Segment");

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
            shape = new Rectangle(x, y, width, height);
            break;
        }
        case 2: {
            int x = Prompter::promptInt("Enter the x of the circle");
            int y = Prompter::promptInt("Enter the y of the circle");
            int r = Prompter::promptInt("Enter the radius of the circle");
            shape = new Circle(x, y, r);
            break;
        }
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }

    file << shape->getSVGTag() << "\n";

    file << "</svg>";
    file.close();

    return 0;
}

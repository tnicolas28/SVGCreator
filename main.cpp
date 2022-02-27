<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>

#include "src/helpers/Prompter.h"
#include "src/shapes/rectangle.h"
#include "src/shapes/circle.h"
#include "src/shapes/point.h"
#include "src/shapes/segment.h"
#include "src/shapes/polygon.h"

std::string readFileIntoString(const std::string& path){
    std::ifstream input_file(path);
    if(!input_file.is_open()){
        std::cerr << "Couldn't open the file" << std::endl;
        exit(EXIT_FAILURE);
    }

    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

std::string eraseLineFromStringFromSpecificWord(std::string stringToLookInto,std::string wordToFind){
    size_t rectPos = stringToLookInto.find(wordToFind);
    size_t findN   = stringToLookInto.find('\n',rectPos);
    size_t findPreviousN = stringToLookInto.rfind('\n',rectPos);

    return stringToLookInto.erase(findPreviousN,findN - findPreviousN);
}

std::vector<std::string> FindAllId(std::string stringToAnalyze){

    std::vector<std::string> elementsList;

    size_t position = stringToAnalyze.find("id='",0);

    do{

        elementsList.push_back(stringToAnalyze.substr(position + 4,6));
        position = stringToAnalyze.find("id='", position + 1);

    }while(position != std::string::npos);

    return elementsList;
}

std::string getFileContentBetweenSVGTags(std::string fileContent) {

    std::string content;

    size_t position = fileContent.find("\n",0);
    size_t positionClosingTag = fileContent.find("</svg>",0);
    size_t lastPositionN      = fileContent.rfind("\n",positionClosingTag);

    content = fileContent.substr(position,lastPositionN - position);

    return content;
}

int main() {
    // Prompt user input
    /*std::vector<std::string> shapes;
    int userChoice;

    shapes.push_back("Rectangle");
    shapes.push_back("Circle");
    shapes.push_back("Polygon");
    shapes.push_back("Segment");

<<<<<<< HEAD
    do {
        std::cout << "Which action do you want to perform ? \n"
                  << "1- Draw a new svg \n"
                  << "2- Delete shape from a svg \n"
                  << "3- Merge two svg's \n"
                  << std::endl;
=======
    std::vector<std::string> colors;
    colors.push_back("transparent");
    colors.push_back("red");
    colors.push_back("purple");
    colors.push_back("green");

    for(int i = 1; i <= shapes.size() ; i++){
        std::cout << "  " <<i << ". " << shapes[i - 1] << std::endl;
    }
>>>>>>> feature/polygon

        userChoice = Prompter::promptInt("Choose the action you want to perform");

    }while(!(userChoice <= 1 && userChoice <= 4));

    if(userChoice == 1) {


        for (int i = 1; i <= shapes.size(); i++) {
            std::cout << "  " << i << ". " << shapes[i - 1] << std::endl;
        }

        std::string fileName;

        do {
            userChoice = Prompter::promptInt("Choose the shape you want to draw");

            if (!(1 <= userChoice && userChoice <= 4)) {
                std::cout << "Please enter a valid choice" << std::endl;
            }
        } while (!(1 <= userChoice && userChoice <= 4));

        std::cout << "You decided to draw : " << shapes[userChoice - 1] << std::endl;

        // Write to SVG

        std::ofstream file;
        file.open("new_svg.svg", std::ofstream::out);

<<<<<<< HEAD
        if (!file) {
            std::cout << "Unable to create a new file" << std::endl;
            return 1;
        }

        file << "<svg width='100' height='100' xmlns='http://www.w3.org/2000/svg'>" << "\n";

        Shape *shape;

        switch (userChoice) {
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
    } else if(userChoice == 2 ){
        //Delete shape from an existing SVG

        //List all elements from the SVG file


    } else if(userChoice == 3){
        //Merge 2 svg

    }*/

    //Suppression d'élement dans le SVG
    std::string myString;
    std::ofstream file;
    std::vector<std::string> elementsList;
    int userChoice;

    myString = readFileIntoString("new_svg.svg");

    std::string content1 = getFileContentBetweenSVGTags(myString);

    myString = readFileIntoString("new_svg1.svg");

    std::string content2 = getFileContentBetweenSVGTags(myString);

    std::string fullContent = content1 + content2;

    std::cout << fullContent;

    file.open("new_svg3.svg");

        file << "<svg width='100' height='100' xmlns='http://www.w3.org/2000/svg'>" << std::endl;
        file << fullContent << std::endl;
        file << "</svg>" << std::endl;

    file.close();

    /*std::cout << myString << std::endl;

    std::string substring = myString.substr(myString.find("id='") + 4,6);

    elementsList = FindAllId(myString);

    for(int i = 1; i <= elementsList.size(); i++){
        std::cout << i << " : " << elementsList[i - 1] << std::endl;
=======
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
>>>>>>> feature/polygon
    }
    std::cout << "Choisissez l'élement à supprimer" << std::endl;
    std::cin  >> userChoice;



    myString = eraseLineFromStringFromSpecificWord(myString,elementsList[userChoice - 1]);

    std::cout << myString << std::endl;

    file.open("new_svg.svg",std::ofstream::out | std::ofstream::trunc);
    file.close();

    file.open("new_svg.svg",std::ofstream::out);
    file << myString;
    file.close();*/

    //Fusion de deux dessins en SVG


    return 0;
}
=======
#include<iostream>

int main(int argc, char** argv) {
  
    std::cout << "Hello SVGCreator" << std::endl;
    return 0;
}
>>>>>>> main

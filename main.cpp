#include <iostream>
#include <vector>
#include <fstream>

#include "src/helpers/Prompter.h"
#include "src/shapes/rectangle.h"
#include "src/shapes/circle.h"
#include "src/shapes/point.h"
#include "src/shapes/segment.h"
#include "src/shapes/polygon.h"
#include "src/helpers/FileHelper.h"

int main() {
    // Prompt user input
    std::vector<std::string> shapes;
    std::vector<std::string> colors;
    std::vector<std::string> fileList = FileHelper::storeFileInFolder("svg");
    int userChoice;

    shapes.push_back("Rectangle");
    shapes.push_back("Circle");
    shapes.push_back("Polygon");
    shapes.push_back("Segment");

    colors.push_back("transparent");
    colors.push_back("red");
    colors.push_back("purple");
    colors.push_back("green");

    do {
        std::cout << "Which action do you want to perform ? \n"
                  << "1- Draw a new svg \n"
                  << "2- Delete shape from a svg \n"
                  << "3- Merge two svg's \n"
                  << "4- Display your library \n"
                  << "5- Display content of a svg \n"
                  << std::endl;

        userChoice = Prompter::promptInt("Choose the action you want to perform");

    }while(!(userChoice >= 1 && userChoice <= 5));

    if(userChoice == 1) {

        for (int i = 1; i <= shapes.size(); i++) {
            std::cout << "  " << i << ". " << shapes[i - 1] << std::endl;
        }

        do {
            userChoice = Prompter::promptInt("Choose the shape you want to draw");

            if (!(1 <= userChoice && userChoice <= 4)) {
                std::cout << "Please enter a valid choice" << std::endl;
            }
        } while (!(1 <= userChoice && userChoice <= 4));

        std::cout << "You decided to draw : " << shapes[userChoice - 1] << std::endl;

        // Write to SVG

        std::ofstream file;
        file.open("svg/" + Prompter::promptString("Choose your filename")+".svg");

        if (!file) {
            std::cout << "Unable to create a new file" << std::endl;
            return 1;
        }

        file << "<svg width='300' height='300' xmlns='http://www.w3.org/2000/svg'>" << "\n";

        Shape *shape;

        switch(userChoice) {

            case 1: {
                int x = Prompter::promptInt("Enter the x of the rectangle");
                int y = Prompter::promptInt("Enter the y of the rectangle");
                int width = Prompter::promptInt("Enter the width of the rectangle");
                int height = Prompter::promptInt("Enter the height of the rectangle");

                std::string fill;
                std::string stroke;

                FileHelper::displayColor(colors);

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

                FileHelper::displayColor(colors);

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

                FileHelper::displayColor(colors);

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

                FileHelper::displayColor(colors);

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

    } else if(userChoice == 2 ){
        //Delete shape from an existing SVG
        std::string myString;
        std::ofstream file;
        std::vector<std::string> elementsList;

        std::string substring = myString.substr(myString.find("id='") + 4,6);

        elementsList = FileHelper::findAllId(myString);

        for(int i = 1; i <= elementsList.size(); i++) {
            std::cout << i << " : " << elementsList[i - 1] << std::endl;
        }

            std::cout << "Choisissez l'élement à supprimer" << std::endl;
            std::cin  >> userChoice;


            myString = FileHelper::eraseLineFromStringFromSpecificWord(myString,elementsList[userChoice - 1]);

            std::cout << myString << std::endl;

            file.open("new_svg.svg",std::ofstream::out | std::ofstream::trunc);
            file.close();

            file.open("new_svg.svg",std::ofstream::out);
            file << myString;
            file.close();


    } else if(userChoice == 3) {
        //Merge 2 svg
        std::string myString;
        std::ofstream file;

        for(int i = 1; i <= fileList.size(); i++)
        {
            std::cout << i << " : " <<fileList[i - 1] << std::endl;
        }

        int firstFile = Prompter::promptInt("Choose the first file you want to merge");
        int secondFile = Prompter::promptInt("Choose the second file you want to merge");

        myString = FileHelper::readFileIntoString(fileList[firstFile - 1]);

        std::string content1 = FileHelper::getFileContentBetweenSVGTags(myString);

        myString = FileHelper::readFileIntoString(fileList[secondFile - 1]);

        std::string content2 = FileHelper::getFileContentBetweenSVGTags(myString);

        std::string fullContent = content1 + content2;



        file.open("svg/"+Prompter::promptString("Choose your filename")+".svg");

        file << "<svg width='300' height='300' xmlns='http://www.w3.org/2000/svg'>" << std::endl;
        file << fullContent << std::endl;
        file << "</svg>" << std::endl;

        file.close();

    } else if(userChoice == 4){

        //Display library
        if(fileList.size() == 0){
            std::cout << "No existing file found" << std::endl;
        } else {
            for(int i = 0; i < fileList.size(); i++){
                std::cout << fileList[i] << std::endl;
            }
        }

    } else if (userChoice == 5) {

        for(int i = 1; i <= fileList.size(); i++){
            std::cout << i << " : " << fileList[i - 1] << std::endl;
        }

        userChoice = Prompter::promptInt("Choose the file you want to display the content");

        std::ifstream fileToOpen(fileList[userChoice - 1]);

        if(fileToOpen.is_open()){
            std::cout << fileToOpen.rdbuf();
        }
        else {
            std::cout << "Unable to open the file" << std::endl;
            return 1;
        }

        fileToOpen.close();
    }

    return 0;
}

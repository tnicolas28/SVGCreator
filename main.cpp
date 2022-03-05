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

int promptUserForMainAction() {
    std::cout << "*------------- 🎨 SVG Creator 🎨 -------------*\n"
              << "Welcome to SVG Creator! What do you want to do?\n"
              << "1 - Draw a new svg\n"
              << "2 - Delete shape from a svg\n"
              << "3 - Merge two svg's\n"
              << "4 - Display your library\n"
              << "5 - Display content of a svg\n"
              << "other - Quit the program"
              << std::endl;

    return Prompter::promptInt("Choose the action you want to perform");
}

void drawSVGAction() {
    std::vector<std::string> shapes { "Rectangle", "Circle", "Polygon", "Segment" };
    std::vector<std::string> colors { "black", "white", "red", "blue", "green", "yellow", "purple", "transparent" };

    int svgWidth = Prompter::promptInt("Choose your SVG width");
    int svgHeight = Prompter::promptInt("Choose your SVG height");

    bool shouldContinueToDraw = true;
    int shapeToDraw;

    std::string fileName = Prompter::promptString("Choose your filename");

    std::ofstream file;
    file.open("svg/" + fileName + ".svg");

    file << "<svg width='" << svgWidth
         << "' height='" << svgHeight
         << "' xmlns='http://www.w3.org/2000/svg'>"
         << "\n";

    while(shouldContinueToDraw) {
        // Prompt for shape to draw
        do {
            std::cout << "Available shapes:" << std::endl;
            for (int i = 1; i <= shapes.size(); i++) {
                std::cout << i << " - " << shapes[i - 1] << std::endl;
            }

            shapeToDraw = Prompter::promptInt("Choose the shape you want to draw");

            if (!(1 <= shapeToDraw && shapeToDraw <= 4)) {
                std::cout << "Please enter a valid choice" << std::endl;
            }
        } while (!(1 <= shapeToDraw && shapeToDraw <= 4));

        std::cout << "You decided to draw: " << shapes[shapeToDraw - 1] << std::endl;

        // Write shape to SVG

        if (!file) {
            std::cout << "❌ Unable to create the SVG" << std::endl;
            exit(1);
        }

        Shape *shape;

        switch (shapeToDraw) {
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
                bool shouldAddOtherPoint = true;

                while (shouldAddOtherPoint) {
                    int x = Prompter::promptInt("Enter the x of the point");
                    int y = Prompter::promptInt("Enter the y of the point");
                    point p;
                    p.x = x;
                    p.y = y;
                    points.push_back(p);
                    char shouldStop = Prompter::promptChar("Add another point ? (Y/N)");
                    if (shouldStop == 'Y' || shouldStop == 'y') continue;
                    shouldAddOtherPoint = false;
                }

                FileHelper::displayColor(colors);

                int strokeChoice = Prompter::promptInt("Choose the color of the stroke");
                stroke = colors[strokeChoice - 1];
                int colorChoice = Prompter::promptInt("Choose the filling color");
                fill = colors[colorChoice - 1];
                shape = new Polygon(0, 0, stroke, fill, points);

                break;
            }
            case 4: {
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
                shape = new Segment(0, 0, p1, p2, stroke, fill);
                break;
            }
            default:
                break;
        }

        file << shape->getSVGTag() << "\n";

        shouldContinueToDraw = Prompter::promptBool("Do you want to add a new shape");
    }

    file << "</svg>";
    file.close();
}

void deleteShapeAction() {
    std::string myString;
    std::ofstream file;
    std::vector<std::string> elementsList;

    std::string substring = myString.substr(myString.find("id='") + 4,6);

    elementsList = FileHelper::findAllId(myString);

    for(int i = 1; i <= elementsList.size(); i++) {
        std::cout << i << " : " << elementsList[i - 1] << std::endl;
    }

    int elementToDelete = Prompter::promptInt("Choisissez l'élement à supprimer");

    myString = FileHelper::eraseLineFromStringFromSpecificWord(myString,elementsList[elementToDelete - 1]);

    std::cout << myString << std::endl;

    file.open("new_svg.svg",std::ofstream::out | std::ofstream::trunc);
    file.close();

    file.open("new_svg.svg",std::ofstream::out);
    file << myString;
    file.close();
}

void mergeSVGsAction() {
    std::vector<std::string> fileList = FileHelper::storeFileInFolder("svg");

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
}

void listSVGsAction() {
    std::vector<std::string> fileList = FileHelper::storeFileInFolder("svg");

    if(fileList.size() == 0){
        std::cout << "No existing file found" << std::endl;
    } else {
        for(int i = 0; i < fileList.size(); i++){
            std::cout << fileList[i] << std::endl;
        }
    }
}

void showSVGContentAction() {
    std::vector<std::string> fileList = FileHelper::storeFileInFolder("svg");

    for(int i = 1; i <= fileList.size(); i++){
        std::cout << i << " - " << fileList[i - 1] << std::endl;
    }

    int fileToRead = Prompter::promptInt("Choose the file of which you want to display the content");

    std::ifstream fileToOpen(fileList[fileToRead - 1]);

    if(fileToOpen.is_open()){
        std::cout << fileToOpen.rdbuf() << std::endl;
    }
    else {
        std::cout << "Unable to open the file" << std::endl;
        exit(1);
    }

    fileToOpen.close();
}

int main() {
    // Main menu
    int shouldPromptForMainAction = true;

    while (shouldPromptForMainAction) {
        int mainAction = promptUserForMainAction();

        switch (mainAction) {
            case 1: {
                // Draw new SVG
                drawSVGAction();
                break;
            }

            case 2: {
                // Delete shape from an existing SVG
                deleteShapeAction();
                break;
            }

            case 3: {
                // Merge 2 SVG files
                mergeSVGsAction();
                break;
            }

            case 4: {
                // List SVG library
                listSVGsAction();
                break;
            }

            case 5: {
                // Show SVG content
                showSVGContentAction();
                break;
            }

            default: {
                std::cout << "Bye bye! See you later 👋" << std::endl;
                shouldPromptForMainAction = false;
                break;
            }
        }
    }

    return 0;
}
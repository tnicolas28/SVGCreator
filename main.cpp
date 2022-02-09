#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char** argv) {


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

    std::cout << "Choose the shape you want to draw : "; 
    std::cin >> userChoice;

    if( userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4){
        std::cout << "Incorrect choice" << std::endl;
    }
    else {

        std::cout << "You decided to draw : " << shapes[userChoice - 1] << std::endl;

        std::ofstream file;

        file.open("new_svg.svg",std::ofstream::out);

        if(!file){
            std::cout << "Unable to create a new file" << std::endl;
        }

        if(userChoice == 1)
        {
            //Let try to draw a rectangle over here
        }
        else if(userChoice == 2){
            //Circle
        }

        file.close();

    }
    

    return 0;
}
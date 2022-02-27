//
// Created by BROUILLE Théo on 20/02/2022.
//

#include "Prompter.h"

int Prompter::promptInt(std::string label) {
    int response;
    std::cout << label << ": ";
    std::cin >> response;
    return response;
}
char Prompter::promptChar(std::string label){
    char response;
    std::cout << label << ": ";
    std::cin >> response;
    return response;
}

std::string Prompter::promptString(std::string label) {
    std::string response;
    std::cout << label << ": ";
    std::cin >> response;

    return response;
}
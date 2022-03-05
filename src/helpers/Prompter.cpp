//
// Created by BROUILLE Théo on 20/02/2022.
//

#include "Prompter.h"

bool Prompter::promptBool(std::string label) {
    char response;
    std::cout << label << " (y/n): ";
    std::cin >> response;
    return response == 'y' || response == 'Y';
}

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

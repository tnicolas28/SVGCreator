//
// Created by BROUILLE Théo on 20/02/2022.
//

#ifndef SVG_CREATOR_PROMPTER_H
#define SVG_CREATOR_PROMPTER_H

#include <string>
#include <iostream>

class Prompter {
public:
    static bool promptBool(std::string label);
    static int promptInt(std::string label);
    static char promptChar(std::string label);
    static std::string promptString(std::string label);
};


#endif //SVG_CREATOR_PROMPTER_H

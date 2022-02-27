//
// Created by Nicolas TRAN on 27/02/2022.
//

#ifndef SVG_CREATOR_FILEHELPER_H
#define SVG_CREATOR_FILEHELPER_H

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>

class FileHelper {
    public :
        static std::string readFileIntoString(const std::string& path);
        static std::string eraseLineFromStringFromSpecificWord(std::string stringToLookInto,std::string wordToFind);
        static std::vector<std::string> findAllId(std::string stringToAnalyze);
        static std::vector<std::string> storeFileInFolder(std::string path);
        static std::string getFileContentBetweenSVGTags(std::string fileContent);
        static void displayColor(std::vector<std::string> colorList);

};


#endif //SVG_CREATOR_FILEHELPER_H

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
        static std::vector<std::string> storedFileInFolder(std::string path);
        static std::string getFileContentBetweenSVGTags(std::string fileContent);
        static std::vector<std::string> split(const std::string& s, char separator);
        static void displayColor(std::vector<std::string> colorList);
};


#endif //SVG_CREATOR_FILEHELPER_H

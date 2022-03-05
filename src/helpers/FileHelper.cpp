//
// Created by Nicolas TRAN on 27/02/2022.
//

#include "FileHelper.h"

std::string FileHelper::readFileIntoString(const std::string& path){
    std::ifstream input_file(path);
    if(!input_file.is_open()){
        std::cerr << "Couldn't open the file" << std::endl;
        exit(EXIT_FAILURE);
    }

    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

std::vector<std::string> FileHelper::storedFileInFolder(std::string path){
    std::vector<std::string> fileList;

    for(const auto & entry : std::filesystem::directory_iterator(path)){
        fileList.push_back(entry.path());
    }

    return fileList;
}

void FileHelper::displayColor(std::vector<std::string> colorList){
    std::cout << "Available colors:" << std::endl;
    for(int i = 1; i <= colorList.size() ; i++){
        std::cout << i << " - " << colorList[i - 1] << std::endl;
    }
}

std::string FileHelper::getFileContentBetweenSVGTags(std::string fileContent) {

    std::string content;

    size_t position = fileContent.find("\n",0);
    size_t positionClosingTag = fileContent.find("</svg>",0);
    size_t lastPositionN      = fileContent.rfind("\n",positionClosingTag);

    content = fileContent.substr(position,lastPositionN - position);

    return content;
}

std::vector<std::string> FileHelper::split(const std::string& s, char separator) {
    std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(separator, pos)) != std::string::npos) {
        std::string substring( s.substr(prev_pos, pos-prev_pos) );

        output.push_back(substring);

        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos-prev_pos));

    return output;
}

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

std::string FileHelper::eraseLineFromStringFromSpecificWord(std::string stringToLookInto,std::string wordToFind){
    size_t rectPos = stringToLookInto.find(wordToFind);
    size_t findN   = stringToLookInto.find('\n',rectPos);
    size_t findPreviousN = stringToLookInto.rfind('\n',rectPos);

    return stringToLookInto.erase(findPreviousN,findN - findPreviousN);
}

std::vector<std::string> FileHelper::findAllId(std::string stringToAnalyze){

    std::vector<std::string> elementsList;

    size_t position = stringToAnalyze.find("id='",0);

    do{

        elementsList.push_back(stringToAnalyze.substr(position + 4,6));
        position = stringToAnalyze.find("id='", position + 1);

    }while(position != std::string::npos);

    return elementsList;
}

std::vector<std::string> FileHelper::storeFileInFolder(std::string path){
    std::vector<std::string> fileList;

    for(const auto & entry : std::filesystem::directory_iterator(path)){
        fileList.push_back(entry.path());
    }

    return fileList;
}

void FileHelper::displayColor(std::vector<std::string> colorList){
    for(int i = 1; i <= colorList.size() ; i++){
        std::cout << "  " <<i << ". " << colorList[i - 1] << std::endl;
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

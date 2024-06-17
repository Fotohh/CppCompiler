#include <iostream>
#include <fstream>
#include <fileapi.h>

#include "Tokenize.h"


int main() {

    std::ifstream stream("./test.xh");

    if (!stream.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string str;
    std::string file_contents;

    while (std::getline(stream, str)) {
        file_contents.append(str);
        file_contents.push_back('\n');
    }

    std::cout << "Hello World" << std::endl;

    std::vector<Token> vec = TOKENIZE_H::bufferFile(file_contents);
    for (Token tok : vec) {
        std::cout << tok.getType() << std::endl;
        std::cout << tok.getValue().value() << std::endl;
    }
    
    return 0;
}

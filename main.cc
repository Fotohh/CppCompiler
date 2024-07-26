#include <iostream>
#include <fstream>
#include <fileapi.h>
#include <bits/fs_fwd.h>
#include <bits/fs_path.h>

#include "Tokenize.h"


int main() {

    const auto path = std::filesystem::path(R"(C:\Users\zinha\OneDrive\Documents\GitHub\CppCompiler\test.xh)");

    std::ifstream stream(path);

    stream.open(path);

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


#ifndef TOKENIZE_H
#define TOKENIZE_H
#include <vector>

#include "StringVector.h"
#include "Token.h"

inline std::vector<std::string> bufferFile(std::string& input) {
    StringVector vec(input);
    std::vector<std::string> buff_list = {};
    std::string buffer;
    while(vec.at().has_value()) {
        if(std::isalpha(vec.at().value())) {
            vec.consume(buffer);
            while(vec.at().has_value() && std::isalnum(vec.at().value())) {
                vec.consume(buffer);
            }
            buff_list.push_back(buffer);
            buffer.clear();
        }else if(std::isdigit(vec.at().value())) {
            
        }
    }
    return buff_list;
}

#endif //TOKENIZE_H

#ifndef TOKENIZE_H
#define TOKENIZE_H
#include <vector>
#include <optional>

#include "StringVector.h"
#include "Token.h"

inline Token tokenSearch(const std::string& buf) {
    if (buf == "quit") {
        return Token(TokenType::QUIT, buf);
    }
    else if (buf == "(") {
        return Token(TokenType::O_P, buf);
    }
    else if (buf == ")") {
        return Token(TokenType::C_P, buf);
    }
    else if (buf == ";") {
        return Token(TokenType::S_C, buf);
    } else {
        throw _invalid_parameter;
    }
}

inline std::vector<Token> bufferFile(const std::string& input) {
    StringVector vec(input);
    std::vector<Token> buff_list = {};
    std::string buffer;
    while(vec.at().has_value()) {
        if(std::isalpha(vec.at().value())) {
            vec.consume(buffer);
            while(vec.at().has_value() && std::isalnum(vec.at().value())) {
                vec.consume(buffer);
            }
            buff_list.push_back(tokenSearch(buffer));
            buffer.clear();
        }else if(std::isdigit(vec.at().value())) {
            vec.consume(buffer);
            while (vec.at().has_value() && std::isdigit(vec.at().value())) {
                vec.consume(buffer);
            }
            buff_list.push_back(Token(TokenType::INT, std::stoi(buffer)));
            buffer.clear();
        }
    }
    return buff_list;
}



#endif //TOKENIZE_H
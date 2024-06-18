
#ifndef TOKENIZE_H
#define TOKENIZE_H
#include <functional>
#include <vector>
#include <optional>

#include "StringVector.h"
#include "Token.h"

inline Token tokenSearch(const std::string& buf) {
    if (buf == "quit") {
        return Token(TokenType::QUIT, buf);
    }
    if (buf == "(") {
        return Token(TokenType::O_P, buf);
    }
    if (buf == ")") {
        return Token(TokenType::C_P, buf);
    }
    if (buf == ";") {
        return Token(TokenType::S_C, buf);
    }
    throw ERROR_SEVERITY_ERROR;
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
            buff_list.emplace_back(TokenType::INT, buffer);
            buffer.clear();
        }
    }
    return buff_list;
}

inline void readTokens(std::vector<Token>& tokens) {
    for(int i = 0; i < tokens.size(); i++) {
        if(tokens.at(i).getType() == TokenType::QUIT) {
            i++;
            int val = 0;
            if(tokens.at(i).getType() == TokenType::O_P) {
                i++;
                if(tokens.at(i).getType() == TokenType::INT) {
                    val = std::stoi(tokens.at(i).getValue().value());
                    i++;
                    if(tokens.at(i).getType() == TokenType::C_P) {
                        i++;
                        if(tokens.at(i).getType() == TokenType::S_C) {
                            exit(val);
                        }
                    }
                }
            }
        }
    }
}



#endif //TOKENIZE_H
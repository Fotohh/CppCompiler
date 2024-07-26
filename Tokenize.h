
#ifndef TOKENIZE_H
#define TOKENIZE_H
#include <vector>
#include <optional>

#include "StringVector.h"
#include "Token.h"
#include "TokenType.h"

inline Token tokenSearch(const std::string& buf) {
    if (buf == "quit") {
        return Token(QUIT, buf);
    }
    if (buf == "(") {
        return Token(O_P, buf);
    }
    if (buf == ")") {
        return Token(C_P, buf);
    }
    if (buf == ";") {
        return Token(S_C, buf);
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
            buff_list.emplace_back(INT_LIT, buffer);
            buffer.clear();
        }
    }
    return buff_list;
}

inline void readTokens(std::vector<Token>& tokens) {
    for(int i = 0; i < tokens.size(); i++) {
        if(tokens.at(i).getType() == QUIT) {
            i++;
            if(tokens.at(i).getType() == O_P) {
                i++;
                if(tokens.at(i).getType() == INT_LIT) {
                    int val = std::stoi(tokens.at(i).getValue().value());
                    i++;
                    if(tokens.at(i).getType() == C_P) {
                        i++;
                        if(tokens.at(i).getType() == S_C) {
                            exit(val);
                        }
                    }
                }
            }
        }
    }
}



#endif //TOKENIZE_H
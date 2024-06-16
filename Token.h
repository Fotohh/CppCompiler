
#ifndef TOKEN_H
#define TOKEN_H

#include <optional>
#include <string>

#include "TokenType.h"

class Token {

public:
    explicit Token(const TokenType type, std::optional<std::string>& value) : type_(type), value_(value) {}

    const TokenType& getType();

    const std::optional<std::string>& getValue();

private:
    TokenType type_;
    const std::optional<std::string>& value_;

};



#endif //TOKEN_H

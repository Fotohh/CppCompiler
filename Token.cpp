
#include "Token.h"

const TokenType &Token::getType() {
   return type_;
}

const std::optional<std::string> &Token::getValue() {
    return value_;
}




#include "Token.h"

int Token::getType() {
   return type_;
}

const std::optional<std::string> &Token::getValue() {
    return value_;
}



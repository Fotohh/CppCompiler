
#ifndef TOKEN_H
#define TOKEN_H

#include <optional>
#include <string>

#include "TokenType.h"

class Token {

public:
    explicit Token(TokenType type, const std::optional<std::string>& value = {}) {

    };

};



#endif //TOKEN_H

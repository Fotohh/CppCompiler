
#ifndef TOKEN_H
#define TOKEN_H

#include <optional>
#include <string>

class Token {

public:

    explicit Token(const int type, const std::string& value) : type_(type), value_(value) {}

    int getType();

    const std::optional<std::string>& getValue();

private:
    int type_;
    const std::optional<std::string>& value_;

};



#endif //TOKEN_H

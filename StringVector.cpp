
#include "StringVector.h"

std::vector<char32_t> StringVector::toVector() {
    std::vector<char32_t> vec;
    for(const char& c : str) {
        vec.push_back(c);
    }
    return vec;
}

const char &StringVector::peek(const int seek) {
    return str.at(index + seek);
}

void StringVector::consume(std::string& target) {
    target.push_back(str.at(index++));
}

char StringVector::charAt(const int index) {
    return str.at(index);
}

std::string &StringVector::getString() {
    return str;
}

const std::optional<char> &StringVector::at() {
    return str.at(index);
}








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

char StringVector::consume() {
    return str.at(index++);
}

char StringVector::charAt(const int index) {
    return str.at(index);
}





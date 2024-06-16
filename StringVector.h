
#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H

#include <string>
#include <utility>
#include <vector>

class StringVector {
public:
    explicit StringVector(std::string& str) : str(std::move(str)) {}

    ~StringVector() {
        std::free(&str);
    }

    std::vector<char32_t> toVector();

    const char& peek(int seek = 0);

    char consume();

    char charAt(int index);

private:
    std::string str;
    int index = 0;
};



#endif //STRINGVECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#ifndef TXTARCHIVER_ARCHIVER_H
#define TXTARCHIVER_ARCHIVER_H


class Archiver {
private:
    std::string data;
    std::string file_path;
    std::map<char, std::string> codes;

    void genCodes();

    std::string strCodes();

    void sepCodes();

    int findSym(const std::string &code);

public:
    Archiver();

    explicit Archiver(const std::string &s, bool fromfile = false);

    std::string encode();

    std::string archExtension();

    std::string decode(bool &err);
};

std::string fileExtension(const std::string &filename);


#endif //TXTARCHIVER_ARCHIVER_H

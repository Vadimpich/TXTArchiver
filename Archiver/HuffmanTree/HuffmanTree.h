#include <string>
#include <map>

#ifndef TXTARCHIVER_HUFFMANTREE_H
#define TXTARCHIVER_HUFFMANTREE_H


class HuffmanTree {
private:
    std::string text;

    struct HuffmanNode;
    struct Compare;

    void getHuffmanCodes(HuffmanNode *root, std::string code, std::map<char, std::string> &codes);

public:
    explicit HuffmanTree(const std::string& s);
    void buildHuffmanTree(std::map<char, std::string> &codes);
};


#endif //TXTARCHIVER_HUFFMANTREE_H

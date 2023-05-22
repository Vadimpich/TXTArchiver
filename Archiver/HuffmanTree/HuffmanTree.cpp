#include "HuffmanTree.h"
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

// Узел дерева Хаффмана
struct HuffmanTree::HuffmanNode {
    int data;
    unsigned frequency;
    HuffmanNode* left, * right;

    HuffmanNode(int data, unsigned frequency)
            : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Функция для сравнения узлов в очереди приоритетов
struct HuffmanTree::Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r)
    {
        return l->frequency > r->frequency;
    }
};

// Функция для сохранения кода Хаффмана для каждого символа
void HuffmanTree::getHuffmanCodes(HuffmanNode* root, string code, map<char, string>& codes)
{
    if (root == nullptr)
        return;

    if (root->data != 9999) {
        codes[char(root->data)] = code;
    }

    getHuffmanCodes(root->left, code + "0", codes);
    getHuffmanCodes(root->right, code + "1", codes);
}

// Функция для построения дерева Хаффмана и получения кодов для каждого символа
void HuffmanTree::buildHuffmanTree(map<char, string>& codes)
{
    // Подсчет частоты каждого символа
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Создание очереди приоритетов с узлами дерева Хаффмана
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Построение дерева Хаффмана
    while (pq.size() != 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* newNode = new HuffmanNode(9999, left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    getHuffmanCodes(pq.top(), "", codes);
}

HuffmanTree::HuffmanTree(const std::string& s) {
    this->text = s;
}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

#include "Archiver.h"
#include "HuffmanTree/HuffmanTree.h"

using namespace std;


Archiver::Archiver() = default;

// Чтение всего текста из файла
string readAll(istream &in) {
    ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

Archiver::Archiver(const std::string &s, bool fromfile) {
    if (fromfile) {
        file_path = s;
        ifstream file(s, ios::binary);
        data = readAll(file);
        file.close();
    } else {
        data = s;
    }
}

// Запись кодов Хаффмана в объект
void Archiver::genCodes() {
    auto hTree = HuffmanTree(data);
    hTree.buildHuffmanTree(codes);
}

int Archiver::countCodes() {
    if (codes.empty()) {
        sepCodes();
    }
    return int(codes.size());
}

string Archiver::strCodes() {
    stringstream ss;
    for (const auto &pair: codes) {
        ss << int(pair.first) << " " << pair.second << " ";
    }
    return ss.str();
}

// Выделение кодов Хаффмана из текста (при дешифровке)
void Archiver::sepCodes() {
    data = data.substr(data.find('\n') + 1);
    stringstream ss(data);
    string codesStr;
    getline(ss, codesStr);
    ss = stringstream(codesStr);
    string curSym, curCode;
    while (ss >> curSym) {
        ss >> curCode;
        codes[char(stoi(curSym))] = curCode;
    }
    data = data.substr(data.find('\n') + 1);
}

// Поиско символа по коду
int Archiver::findSym(const std::string &code) {
    for (const auto &pair: codes) {
        if (pair.second == code) {
            return int(pair.first);
        }
    }
    return 9999;
};

string decimalToBinary(int decimal) {
    if (decimal == 0)
        return "0";
    string binary;
    while (decimal > 0) {
        int rem = decimal % 2;
        binary = to_string(rem) + binary;
        decimal /= 2;
    }
    return binary;
}

int binaryToDecimal(const string &binary) {
    int decimal = 0;
    size_t power = binary.length() - 1;
    for (char digit: binary) {
        if (digit == '1')
            decimal += int(pow(2, power));
        power--;
    }
    return decimal;
}

// Возвращает расширение из названия файла
string fileExtension(const string &filename) {
    size_t dotIndex = filename.rfind('.');
    if (dotIndex != string::npos) {
        string extension = filename.substr(dotIndex + 1);
        return extension;
    }
    return "txt";
}

// Возвращает расширение заархивированного файла
string Archiver::archExtension() {
    stringstream ss(data);
    string ext;
    getline(ss, ext);
    return "." + ext;
}

// Архивация (сжатие) текста
std::string Archiver::encode() {
    genCodes();
    string encodedData;
    encodedData += fileExtension(file_path) + "\n";
    encodedData += strCodes() + "\n";
    string binData;
    for (const char c: data) {
        binData += codes[c];
    }
    for (int i = 0; i < binData.length(); i += 7) {
        string oneByte = binData.substr(i, 7);
        encodedData += char(binaryToDecimal(oneByte));
    }
    return encodedData;
}

string addLeadingZeros(string str) {
    size_t numZerosToAdd = 7 - str.length();
    if (numZerosToAdd <= 0)
        return str;
    string result;
    for (int i = 0; i < numZerosToAdd; i++) {
        result += "0";
    }
    result += str;
    return result;
}

// Разархивация текста
std::string Archiver::decode(bool &err) {
    if (codes.empty()) {
        sepCodes();
    }
    string decodedData;
    string binData;
    size_t t = data.length();
    for (int i = 0; i < data.length(); i++) {
        char c = data[i];
        string binCode = decimalToBinary(int(c));
        if (i != data.length() - 1) {
            binCode = addLeadingZeros(binCode);
        }
        binData += binCode;
    }

    map<string, char> reversedCodes;
    for (const auto &pair: codes) {
        reversedCodes[pair.second] = pair.first;
    }

    int n = 0;
    for (int i = 0; i < binData.length();) {
        n++;
        string code = binData.substr(i, n);
        if (reversedCodes.count(code)) {
            char c = reversedCodes[code];
            decodedData += c;
            i += n;
            n = 0;
        } else if (i + n > binData.length()) {
            err = true; // Для вывода предупреждения
            return decodedData;
        }
    }
    return decodedData;
}



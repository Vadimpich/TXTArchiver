#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"
#include "Archiver.h"
#include "Messages.h"

using namespace std;

bool is_number(const string &s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// Защита от ввода не числовой строки
void getNumberLine(string &s, bool ru) {
    getline(cin, s);
    while (!is_number(s)) {
        cout << ((ru) ? RU_MSG_WRONG_INPUT : EN_MSG_WRONG_INPUT) << endl;
        getline(cin, s);
    }
}

// Выбор пункта меню
int UI::choice() const {
    string inp;
    getNumberLine(inp, ru);
    int iinp = stoi(inp);
    while (iinp < 1 || iinp > 3) {
        cout << ((ru) ? RU_MSG_WRONG_INPUT : EN_MSG_WRONG_INPUT) << endl;
        getNumberLine(inp, ru);
        iinp = stoi(inp);
    }
    return iinp;
}

// Главное меню
void UI::menuMain() {
    cout << ((ru) ? RU_MSG_MENU : EN_MSG_MENU) << endl;
    switch (choice()) {
        case 1:
            menuEncode();
            break;
        case 2:
            menuDecode();
            break;
        case 3:
            return;
    };
}

bool fileExists(const string &filename) {
    ifstream file(filename);
    return file.good();
}

// Генерация файла с уникальным названием (добавление цифр в конец)
string generateUniqueFilename(const string &filename) {
    if (!fileExists(filename)) {
        return filename;
    }
    string uniqueFilename = filename;
    int counter = 1;
    size_t dotIndex = uniqueFilename.rfind('.');
    string extension;
    if (dotIndex != string::npos) {
        extension = uniqueFilename.substr(dotIndex);
        uniqueFilename = uniqueFilename.substr(0, dotIndex);
    }
    while (fileExists(uniqueFilename + "_" + to_string(counter) + extension)) {
        counter++;
    }
    return uniqueFilename + "_" + std::to_string(counter) + extension;
}

// Название файла без расширения
string removeExtension(const string &filename) {
    size_t dotIndex = filename.rfind('.');
    if (dotIndex != string::npos) {
        return filename.substr(0, dotIndex);
    }
    return filename;
}

// Меню разархивации
void UI::menuDecode() {
    string inp;
    cout << ((ru) ? RU_MSG_DECODE : EN_MSG_DECODE) << endl;
    getline(cin, inp);
    if (!fileExists(inp)) {
        cout << ((ru) ? RU_MSG_NO_FILE : EN_MSG_NO_FILE) << endl;
        menuMain();
        return;
    }
    if (fileExtension(inp) != "txtarch") {
        cout << ((ru) ? RU_MSG_DECODE_ERROR : EN_MSG_DECODE_ERROR) << endl;
        menuMain();
        return;
    }
    arch = Archiver(inp, true);
    string ext = arch.archExtension();
    string filename = generateUniqueFilename(removeExtension(inp) + ext);
    bool err = false;
    string encoded = arch.decode(err);
    if (err) {
        cout << ((ru) ? RU_MSG_DECODE_CORRUPTED : EN_MSG_DECODE_CORRUPTED) << endl;
    }
    ofstream fout(filename, ios::binary);
    fout << encoded;
    fout.close();
    cout << ((ru) ? RU_MSG_FILE_SAVED : EN_MSG_FILE_SAVED) << filename << endl;
}

streampos getFileSize(const string &filename) {
    ifstream file(filename, ifstream::ate | ifstream::binary);
    if (!file) {
        return -1;
    }
    std::streampos fileSize = file.tellg();
    file.close();
    return fileSize;
}

// Меню архивации
void UI::menuEncode() {
    cout << ((ru) ? RU_MSG_ENCODE : EN_MSG_ENCODE) << endl;
    string inp;
    switch (choice()) {
        case 1: {
            cout << ((ru) ? RU_MSG_ENCODE_FILE : EN_MSG_ENCODE_FILE) << endl;
            getline(cin, inp);
            if (!fileExists(inp)) {
                cout << ((ru) ? RU_MSG_NO_FILE : EN_MSG_NO_FILE) << endl;
                menuMain();
                return;
            }
            if (fileExtension(inp) != "txt") {
                cout << ((ru) ? RU_MSG_WRONG_FORMAT : EN_MSG_WRONG_FORMAT) << endl;
            }
            arch = Archiver(inp, true);
            string filename = generateUniqueFilename(removeExtension(inp) + ".txtarch");
            string encoded = arch.encode();
            ofstream fout(filename, ios::binary);
            fout << encoded;
            fout.close();
            cout << ((ru) ? RU_MSG_FILE_SAVED : EN_MSG_FILE_SAVED) << filename << endl;
            int iSize = int(getFileSize(inp));
            int oSize = int(getFileSize(filename));
            if (oSize >= iSize) {
                cout << ((ru) ? RU_MSG_BIGGER_FILE : EN_MSG_BIGGER_FILE) << endl;
            } else {
                double ratio = 100 - double(oSize) / iSize * 100;
                cout.precision(3);
                cout << ((ru) ? RU_MSG_RATIO : EN_MSG_RATIO) << ratio << "%" << endl;
            }
        }
            break;
        case 2: {
            cout << ((ru) ? RU_MSG_ENCODE_CONSOLE : EN_MSG_ENCODE_CONSOLE) << endl;
            getline(cin, inp);
            arch = Archiver(inp);
            string filename = generateUniqueFilename("archived.txtarch");
            string encoded = arch.encode();
            ofstream fout(filename, ios::binary);
            fout << encoded;
            fout.close();
            cout << ((ru) ? RU_MSG_FILE_SAVED : EN_MSG_FILE_SAVED) << filename << endl;
        }
            break;
        case 3:
            menuMain();
            break;
    };
}

UI::UI(bool ru) {
    cout << MSG_LOGO << endl;
    this->ru = ru;
    menuMain();
}


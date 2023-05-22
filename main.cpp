#include <cstring>
#include "Archiver/UI.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");

    bool langRu = true;

    if ((argc == 2) && strcmp(argv[1], "-en") == 0) {
        langRu = false;
    }

    // Открытие меню
    UI menu(langRu);

    // Чтоб консоль не закрывалась
    std::cin.get();

    return 0;
}


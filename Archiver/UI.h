#include "Archiver.h"

#ifndef TXTARCHIVER_UI_H
#define TXTARCHIVER_UI_H


class UI {
public:
    explicit UI(bool ru);

private:
    Archiver arch;
    bool ru;

    int choice() const;

    void menuMain();

    void menuDecode();

    void menuEncode();
};


#endif //TXTARCHIVER_UI_H

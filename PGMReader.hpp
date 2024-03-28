#ifndef _PGM_READER_HPP_
#define _PGM_READER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "ImageReader.hpp"

class PGMReader : public ImageReader {
private:
    int szerokosc;
    int wysokosc;
    int maksWartosc;
    std::unordered_map<int, int> licznikKolorow;

public:
    PGMReader(const std::string& nazwaPliku);

    void drukujInfoObrazu() override;
    void drukujNajczestszyKolor() override;
    int obliczLiczbeUnikalnychKolorow() override;
};

#endif
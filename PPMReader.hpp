#ifndef _PPM_READER_HPP_
#define _PPM_READER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "ImageReader.hpp"

class PPMReader : public ImageReader {
private:
    int szerokosc;
    int wysokosc;
    int maksWartosc;
    std::unordered_map<std::string, int> licznikKolorow;

public:
    PPMReader(const std::string& nazwaPliku);

    void drukujInfoObrazu() override;
    void drukujNajczestszyKolor() override;
    int obliczLiczbeUnikalnychKolorow() override;
};

#endif
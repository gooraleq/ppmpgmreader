#include <iostream>
#include "PGMReader.hpp"
#include "PPMReader.hpp"

int main() {
    PGMReader czytnikPGM("przyklad.pgm");
    ImageReader* czytnikObrazuPGM = &czytnikPGM;

    czytnikObrazuPGM->drukujInfoObrazu();
    czytnikObrazuPGM->drukujNajczestszyKolor();
    std::cout << "Liczba unikalnych kolorow: " << czytnikObrazuPGM->obliczLiczbeUnikalnychKolorow() << std::endl;

    PPMReader czytnikPPM("przyklad.ppm");
    ImageReader* czytnikObrazuPPM = &czytnikPPM;

    czytnikObrazuPPM->drukujInfoObrazu();
    czytnikObrazuPPM->drukujNajczestszyKolor();
    std::cout << "Liczba unikalnych kolorow: " << czytnikObrazuPPM->obliczLiczbeUnikalnychKolorow() << std::endl;

    return 0;
}
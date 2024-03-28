#include "PPMReader.hpp"

PPMReader::PPMReader(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    std::string linia;
    if (plik.is_open()) {
        // Wczytaj numer magiczny (P3)
        std::getline(plik, linia);

        // Pomiñ komentarze
        std::getline(plik, linia);
        while (linia[0] == '#') {
            std::getline(plik, linia);
        }

        // Wczytaj szerokoœæ, wysokoœæ i maksymaln¹ wartoœæ
        std::istringstream wymiary(linia);
        wymiary >> szerokosc >> wysokosc;
        plik >> maksWartosc;

        // Wczytaj wartoœci pikseli i zlicz kolory
        std::string wartoscPiksela;
        while (plik >> wartoscPiksela) {
            licznikKolorow[wartoscPiksela]++;
        }
    }
    else {
        std::cerr << "Blad: Nie mo¿na otworzyæ pliku: " << nazwaPliku << std::endl;
    }
    plik.close();
}

void PPMReader::drukujInfoObrazu() {
    std::cout << "Informacje o obrazie PPM:" << std::endl;
    std::cout << "Szerokosc: " << szerokosc << std::endl;
    std::cout << "Wysokosc: " << wysokosc << std::endl;
    std::cout << "Liczba pikseli: " << szerokosc * wysokosc << std::endl;
    std::cout << "Maksymalna wartosc koloru: " << maksWartosc << std::endl;
}

void PPMReader::drukujNajczestszyKolor() {
    int maxLicznik = 0;
    std::string najczestszyKolor;
    for (const auto& para : licznikKolorow) {
        if (para.second > maxLicznik) {
            maxLicznik = para.second;
            najczestszyKolor = para.first;
        }
    }
    std::cout << "Najczestszy kolor: " << najczestszyKolor << std::endl;
}

int PPMReader::obliczLiczbeUnikalnychKolorow() {
    return licznikKolorow.size();
}

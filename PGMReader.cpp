#include "PGMReader.hpp"

PGMReader::PGMReader(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    std::string linia;
    if (plik.is_open()) {
        // Wczytaj numer magiczny (P2)
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
        int wartoscPiksela;
        while (plik >> wartoscPiksela) {
            licznikKolorow[wartoscPiksela]++;
        }
    }
    else {
        std::cerr << "Blad: Nie mozna otworzyc pliku: " << nazwaPliku << std::endl;
    }
    plik.close();
}

void PGMReader::drukujInfoObrazu() {
    std::cout << "Informacje o obrazie PGM:" << std::endl;
    std::cout << "Szerokosc: " << szerokosc << std::endl;
    std::cout << "Wysokosc: " << wysokosc << std::endl;
    std::cout << "Liczba pikseli: " << szerokosc * wysokosc << std::endl;
    std::cout << "Maksymalna wartosc koloru: " << maksWartosc << std::endl;
}

void PGMReader::drukujNajczestszyKolor() {
    int maxLicznik = 0;
    int najczestszyKolor = 0;
    for (const auto& para : licznikKolorow) {
        if (para.second > maxLicznik) {
            maxLicznik = para.second;
            najczestszyKolor = para.first;
        }
    }
    std::cout << "Najczestszy kolor: " << najczestszyKolor << std::endl;
}

int PGMReader::obliczLiczbeUnikalnychKolorow() {
    return licznikKolorow.size();
}
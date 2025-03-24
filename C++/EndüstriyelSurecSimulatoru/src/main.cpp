#include "simulator.h"

int main() {
    Simulator sim;
    char komut;

    while (true) {
        std::cout << "Komut gir (b: başlat, d: durdur, q: çıkış): ";
        std::cin >> komut;

        if (komut == 'b') {
            sim.baslat();
        } else if (komut == 'd') {
            sim.durdur();
        } else if (komut == 'q') {
            sim.durdur();
            break;
        }
    }

    return 0;
}
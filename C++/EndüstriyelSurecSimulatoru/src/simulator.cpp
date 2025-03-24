#include "simulator.h"

Simulator::Simulator() : calisiyor(false) {}

Simulator::~Simulator() {
    if (calisiyor) {
        durdur();
    }
}

void Simulator::baslat() {
    if (!calisiyor) {
        calisiyor = true;
        simThread = std::thread(&Simulator::calistir, this);
    }
}

void Simulator::durdur() {
    if (calisiyor) {
        calisiyor = false;
        if (simThread.joinable()) {
            simThread.join();
        }
    }
}

bool Simulator::calisiyorMu() {
    return calisiyor;
}

void Simulator::calistir() {
    while (calisiyor) {
        std::cout << "Makine çalışıyor..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Makine durdu." << std::endl;
}
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

class Simulator {
public:
    Simulator();
    ~Simulator();
    void baslat();
    void durdur();
    bool calisiyorMu();

private:
    void calistir();

    std::atomic<bool> calisiyor;
    std::thread simThread;
};

#endif
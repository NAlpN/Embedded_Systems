#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>

struct sensorVerisi{
    double vibrasyon;
    double sicaklik;
    double basinc;
    double gurultu;
    double nem;
    int ariza;
};

std::vector<sensorVerisi> readCSV(const std::string& filename){
    std::vector<sensorVerisi> data;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()){
        std::cerr << "Dosya açılamadı: " << filename << std::endl;
        return data;
    }

    while (std::getline(file, line)){
        std::stringstream ss(line);
        sensorVerisi sensor;
        char comma;
        ss >> sensor.vibrasyon >> comma >> sensor.sicaklik >> comma >> sensor.basinc >> comma >> sensor.gurultu >> comma >> sensor.nem >> comma >> sensor.ariza;
        data.push_back(sensor);
    }
    file.close();
    return data;
}

void RastgeleVeriUretimi(const std::string& filename, int num_samples){
    std::ofstream file(filename);
    
    if (!file.is_open()){
        std::cerr << "Dosya açılamadı: " << filename << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> vib_dist(0.1,2.0);
    std::uniform_real_distribution<double> sic_dist(30.0, 100.0);
    std::uniform_real_distribution<double> bas_dist(100000, 102000);
    std::uniform_real_distribution<double> gur_dist(50.0, 100.0);
    std::uniform_real_distribution<double> nem_dist(20.0, 80.0);
    std::bernoulli_distribution ariza_dist(0.3);

    file << "Vibrasyon,Sıcaklık,Basınç,Gürültü,Nem,Arıza" << std::endl;
    
    for (int i = 0; i < num_samples; ++i){
        file << vib_dist(gen) << ","
             << sic_dist(gen) << ","
             << bas_dist(gen) << ","
             << gur_dist(gen) << ","
             << nem_dist(gen) << ","
             << ariza_dist(gen) << std::endl;
    }
    file.close();
}

int main(){
    std::string filename = "SensorVerileri.csv";
    RastgeleVeriUretimi(filename, 100);

    return 0;
}
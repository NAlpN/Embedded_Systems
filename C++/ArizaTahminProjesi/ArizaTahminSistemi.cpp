#include "eigen/Eigen/Dense"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace Eigen;
using namespace std;

MatrixXd VeriOku(const string& filename, VectorXd& labels){
    ifstream file(filename);
    vector<vector<double>> data;
    vector<double> labelData;
    string line;

    while (getline(file, line)){
        stringstream ss(line);
        vector<double> row;
        string value;
        int colIdx = 0;

        while (getline(ss, value, ',')){
            double val = stod(value);
            
            if (colIdx == 5){
                labelData.push_back(val);
            }else{
                row.push_back(val);
            }
            colIdx++;
        }
        data.push_back(row);
    }

    int rows = data.size();
    int cols = data[0].size();
    MatrixXd matrix(rows, cols);
    labels = VectorXd(rows);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix(i, j) = data[i][j];
        }
        labels(i) = labelData[i];
    }
    
    return matrix;
}

double sigmoid(double z){
    return 1.0 / (1.0 + exp(-z));
}

void LogisticRegressionEgitimi(MatrixXd& X, VectorXd& y, VectorXd& W, double& b, double lr, int epochs){
    int m = X.rows();
    
    for (int i = 0; i < epochs; i++){
        VectorXd z = (X * W).array() + b;
        VectorXd pred = z.unaryExpr(&sigmoid);

        VectorXd error = pred - y;

        VectorXd dW = (X.transpose() * error) / m;
        double db = error.sum() / m;

        W -= lr * dW;
        b -= lr * db;

        if (i % 100 == 0){
            cout << "Epoch: " << i << "- Kayıp: " << error.squaredNorm() / m << endl;
        }
    }
}

double tahmin(VectorXd& X, VectorXd& W, double b){
    double z = X.dot(W) + b;

    return sigmoid(z);
}

double DogrulukHesapla(MatrixXd& X, VectorXd& y, VectorXd& W, double b) {
    int dogruTahmin = 0;
    int toplamVeri = X.rows();

    for (int i = 0; i < toplamVeri; i++) {
        VectorXd örnek = X.row(i);
        double tahminSonucu = tahmin(örnek, W, b);
        int sınıf = (tahminSonucu >= 0.5) ? 1 : 0;

        if (sınıf == y(i))
            dogruTahmin++;
    }

    return (double)dogruTahmin / toplamVeri;
}

int main() {
    string filename = "SensorVerileri.csv";

    VectorXd labels;
    MatrixXd data = VeriOku(filename, labels);

    int features = data.cols();
    VectorXd W = VectorXd::Random(features);
    double b = 0;

    LogisticRegressionEgitimi(data, labels, W, b, 0.01, 1000);

    double dogruluk = DogrulukHesapla(data, labels, W, b);
    cout << "Model Doğruluk Oranı: %" << dogruluk * 100 << endl;

    return 0;
}
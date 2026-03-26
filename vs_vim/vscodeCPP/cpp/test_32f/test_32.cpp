#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    //input
    int m1{}, m2{};
    cout << "m1 = ";
    cin >> m1;
    cout << "m2 = ";
    cin >> m2;

    int v1{}, v2{};
    cout << "v1 = ";
    cin >> v1;
    cout << "v2 = ";
    cin >> v2;


    double energyLoss = 0.5 * (m1 * m2) / (m1 + m2) * pow((v1 - v2), 2);
    double energyTotal = 0.5 * m1 * v1 * v1 + 1/2 * m2 * v2 * v2;


    cout << "energyLoss = " << fixed << setprecision(2) << energyLoss << "J" << '\n';
    cout << "energyTotal = " << fixed << setprecision(2) << energyLoss / energyTotal * 100 << "%" << endl;

    return 0;
}
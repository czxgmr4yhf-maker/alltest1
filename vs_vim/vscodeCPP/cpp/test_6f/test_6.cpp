#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double distance = 2.0;
    const double distanceRate = .98;
    double s;
    cin >> s;
    double sumDistance = 0;
    int steps = 0;

    while (true) {
        if (sumDistance >= s) {
            cout << steps << endl;
            break;
        }else {
            sumDistance += pow(distanceRate, steps++) * distance;
        }
    }
    
    return 0;
}
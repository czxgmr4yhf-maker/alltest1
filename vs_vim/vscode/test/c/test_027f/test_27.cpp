#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double pi = 3.14;

    cout << "please enter a radius: r = ";
    double r;
    cin >> r;
    double circle = pi * r * r; 
    cout << "area  of circle = " << circle;

    return 0;
} 
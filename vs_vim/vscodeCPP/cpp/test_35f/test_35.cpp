#include <iostream>
#include <cmath>
#include <iomanip>
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
using namespace std;
int main() {
    double x1, y1;
    cin >> x1 >> y1;
    double x2, y2;
    cin >> x2 >> y2;
    double x3, y3;
    cin >> x3 >> y3;

    double disA = distance(x1, y1, x2, y2);
    double disB = distance(x2, y2, x3, y3);
    double disC = distance(x1, y1, x3, y3);

    double permeter = disA + disB + disC;
    cout << fixed << setprecision(2) << permeter << endl;

    return 0;
}
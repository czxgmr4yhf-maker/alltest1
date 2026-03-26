#include<iostream>
#include <cmath>
using namespace std;
int main() {
    int x;
    cin >> x;

    int a = sqrt(x);
    if (x == a * (a + 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
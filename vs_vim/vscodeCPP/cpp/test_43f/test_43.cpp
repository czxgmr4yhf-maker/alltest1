#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> binaryChange(int n);
void binaryPrint(int n);
int main() {
    int n;
    cin >> n;

    binaryPrint(n);
    cout << "\n";
    return 0;
}
vector<int> binaryChange(int n) {
    vector<int> power;
    int i{};
    while(n != 0) {
        for (i = 0; pow(2, i) <= n; i++);
        n = n - pow(2, i - 1);
        power.push_back(i - 1);
    }
    return power;
}
void binaryPrint(int n) {
    vector<int> getNumber = binaryChange(n);
    int i;
    for (i = 0; i < getNumber.size(); i++) {
            if (getNumber[i] == 0) {
                cout << "2(0)";
            } else if(getNumber[i] == 1) {
                cout << "2";
            } else {
                cout << "2(";
                binaryPrint(getNumber[i]);
                cout << ")";
            }

            if (i < getNumber.size() - 1) {
                cout << "+";
            }
    }

    return;
}
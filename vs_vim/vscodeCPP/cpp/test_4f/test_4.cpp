#include <iostream>

using namespace std;

bool isPrime (int n);

int main() {
    int sumL{};
    cin >> sumL;

    int sumPrime{};
    int n = 1;
    int num = 0;

    while (true) {
        if (isPrime(++n)) {
            sumPrime += n;
            if (sumPrime <= sumL) {
                cout << n << endl;
                num++;
            }else {
                break;
            }
        }
    }

    cout << num << endl; //output

    return 0;
}

bool isPrime (int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
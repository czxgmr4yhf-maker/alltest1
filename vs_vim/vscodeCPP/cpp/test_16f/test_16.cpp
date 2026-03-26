#include <iostream>

using namespace std;

int main() {
    const int moneyPocket = 300;

    int costArr[12] = {0};
    for (int i = 0; i < 12; i++) {
        cin >> costArr[i];
    }

    int moneyLeave = {};
    int moneySavings = {};
    for (int i = 0; i < 12; i++) {
        moneyLeave += moneyPocket;
        
        if (moneyLeave - costArr[i] >= 100) {
            int n = (moneyLeave - costArr[i]) / 100;
            moneySavings += n * 100;
            moneyLeave = moneyLeave - n * 100 - costArr[i];
        } else if (moneyLeave - costArr[i] < 0) {
            cout << '-' << i + 1 << endl;
            return 0;
        } else {
            moneyLeave = moneyLeave - costArr[i];
        }
    }

    double rate = .2;
    cout << (int)(moneySavings * (1 + rate)) + moneyLeave;

    return 0;
}
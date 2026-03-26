/*gold coin*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int k;
    cin >> k;

    int n = 0;
    int sum = 0;
    while (sum < k ) {
        sum += ++n;
    }

    int sumCoin{};
    for (int i = 1; i < n; i++) {
        sumCoin += pow(i, 2);
    }

    sumCoin += (k - sum + n) * n;
    cout << sumCoin << endl;

    return 0;
}
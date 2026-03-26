#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> pain(n);
    for (int i = 0; i < n; i++) cin >> pain[i];

    int sum = 0;
    for (int i = 0; i < m; i++) sum += pain[i];
    int minSum = sum;

    for (int i = m; i < n; i++) {
        sum = sum + pain[i] - pain[i - m];
        if (sum < minSum) minSum = sum;
    }

    cout << minSum << endl;

    return 0;
}
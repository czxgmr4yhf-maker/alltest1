#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n{};
    cin >> n;

    vector<int> cutes;
    for (int i = 0; i < n; i++) {
        int x{};
        cin >> x;
        cutes.push_back(x);
    }

    vector<int> vanity(n);
    for (int i = 0; i < cutes.size(); i++) {
        for (int k = 0; k < i; k++) {
            if (cutes[k] < cutes[i]) {
                vanity[i] += 1;
            }
        }
    }

    for (int i : vanity) {
        cout << i << " ";
    }

    return 0;
}
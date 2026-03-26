#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> numArry(n);
    for (int &x : numArry) cin >> x;

    reverse(numArry.begin(), numArry.end());
    for (const int &i : numArry) {
        cout << i << " ";
    }
    cout << '\n';
}
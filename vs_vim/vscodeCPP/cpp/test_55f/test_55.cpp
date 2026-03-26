#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int maxNum = max({a, b, c});
        int minNum = min({a, b, c});

        if (maxNum - minNum <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
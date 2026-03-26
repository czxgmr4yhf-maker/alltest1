#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    const char digits[10][5][4] = {
        { "XXX", "X.X", "X.X", "X.X", "XXX" },  // 0
        { "..X", "..X", "..X", "..X", "..X" },  // 1
        { "XXX", "..X", "XXX", "X..", "XXX" },  // 2
        { "XXX", "..X", "XXX", "..X", "XXX" },  // 3
        { "X.X", "X.X", "XXX", "..X", "..X" },  // 4
        { "XXX", "X..", "XXX", "..X", "XXX" },  // 5
        { "XXX", "X..", "XXX", "X.X", "XXX" },  // 6
        { "XXX", "..X", "..X", "..X", "..X" },  // 7
        { "XXX", "X.X", "XXX", "X.X", "XXX" },  // 8
        { "XXX", "X.X", "XXX", "..X", "XXX" }   // 9
    };

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int row = 0; row < 5; row++) {
        for (int k = 0; k < n; k++) {
            if (k != n - 1) {
                cout << digits[s[k] - '0'][row] << '.';
            } else {
                cout << digits[s[k] - '0'][row] << '\n';
            }
        }
    }

}
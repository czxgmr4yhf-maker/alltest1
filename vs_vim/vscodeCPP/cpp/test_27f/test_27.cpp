#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums;
    for (int i = m; i <= n; i++) {
        nums.push_back(i);
    }

    vector<string> strs;
    for (int x : nums) {
        strs.push_back(to_string(x));
    }

    int numArry[10] = {0};
    for (string s : strs) {
        for (char x : s) {
            numArry[x - '0'] += 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << numArry[i] << " ";
    }
    cout << '\n';
    return 0;
}
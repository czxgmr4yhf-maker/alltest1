#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 10;
    cin >> n;

    vector<int> arr;
    vector<int> arrNum;
    for (int i = 0; i < n; i++) {
        int x{};
        cin >> x;
        arr.push_back(x);
    }

    int num{};
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1] - 1) {
            num++;
        }else {
            arrNum.push_back(num + 1);
            num = 0;
        }
    }
    arrNum.push_back(num + 1);

    int maxVal = *max_element(arrNum.begin(), arrNum.end());
    cout << maxVal << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n{};
    cin >> n;

    vector<int> arrNum;
    while(true) {
        if (n == 1) {
            arrNum.push_back(n);
            break;
        }else if (n % 2 == 0) {
            arrNum.push_back(n);
            n /= 2;
        }else {
            arrNum.push_back(n);
            n = 3 * n + 1;
        }
    }

    for (int i = arrNum.size() - 1; i >= 0; i--) {
        cout << arrNum[i] << " ";
    }
    
    return 0;
}

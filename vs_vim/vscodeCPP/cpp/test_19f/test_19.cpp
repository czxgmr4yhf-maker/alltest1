#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numArry;
    while (true) {
        int x{};
        cin >> x;
        
        if (x == 0) break;
        else{
            numArry.push_back(x);
        }
    }

    for (int i = numArry.size() - 1; i >= 0; i-- ) {
        cout << numArry[i] << " ";
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int n{};
    cin >> n;

    int nMin = n / 52 / 7;

    int x{}, k{};

    for (int i = nMin; i > 0; i--) {
        if (i <= 100 && (nMin - i) % 3 == 0 && (nMin - i) / 3 > 0){
            x = i;
            k = (nMin - x) / 3;
            break;
        }
    }

    cout << x << '\n';
    cout << k << endl;

    return 0;
}
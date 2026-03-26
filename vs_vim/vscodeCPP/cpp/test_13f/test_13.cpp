#include <iostream>

using namespace std;

int main() {
    int n{};
    cin >> n;

    int m = 1;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (m <= 9) {
                cout << '0' << m++;
            } else {
                cout << m++;
            }  
        }

        cout << '\n';
    }

    cout << '\n';

    int x = 1;
    int rpN = n;
    for (int i = 0; i < n; i++) {
        for (int j = rpN; j > 1; j--) {
            cout << "  ";
        }

        for (int j = rpN; j <= n; j++) {
            if (x <= 9) {
                cout << '0' << x++;
            } else {
                cout << x++;
            }  
        }

        rpN--;
        cout << '\n';
    }

    return 0;
}
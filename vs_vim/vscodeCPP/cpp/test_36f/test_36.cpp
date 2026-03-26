#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int x);

int main() {
    int n{};
    cin >> n;
    
    vector<int> numArry(n);
    for (int i = 0; i < n; i++) cin >> numArry[i];

    for (int i : numArry) {
        if (isPrime(i)) cout << i << " ";
    }

    return 0;
}

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i <= (int)sqrt(x); i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int main() {
    int num{};
    cin >> num;

    for (int i = 2; i < sqrt(num); i++) {
        if (isPrime(i) && num % i == 0) {
            cout << num / i;
            break;
        }
    }

    return 0;
}

bool isPrime(int n) {
    if (n == 2) return true;
    if (n == 0 || n == 1) return false;

    int limit = sqrt(n);
    for (int i = 3; i <= limit; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
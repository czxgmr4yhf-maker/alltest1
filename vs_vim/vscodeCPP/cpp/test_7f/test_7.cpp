#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n{};
    cin >> n;
    const int rate = 10;
    int rev{};

    if (n > 0) {
        while (n > 0) {
            rev =  rev * rate +n % rate;
            n /= rate;
        }
        cout << rev << endl;
    }else if (n == 0) {
        rev = n;
        cout << rev << endl;
    }else {
        n = abs(n);

        while (n > 0) {
            rev =  rev * rate +n % rate;
            n /= rate;
        }
        
        rev = 0 - rev;
        cout << rev << endl;
    }
    
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector> 
#include <algorithm>

using namespace std;

bool isPrime(int n);
vector<int> generatePalindromes(int min, int max);

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> pals = generatePalindromes(a, b);
    
    for (int x : pals) {
        if (isPrime(x)) {
            cout << x << endl;
        }
    }
    return 0;
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> generatePalindromes(int min, int max) {
    vector<int> pals;

    //single digit number
    for (int i = 1; i < 9; i++) {
        if (i >= min && i <= max) {
            pals.push_back(i);
        }
    }
        
    //generate Even-positioned, odd-positioned palindromes
    for (int len = 2; len <= 8;len++) {
        int halfLen = (len + 1) / 2;
        int start = pow(10, halfLen - 1);
        int end = pow(10, halfLen);

        for (int half = start; half < end; half++) {
            string s = to_string(half);
            string rev = s;
            if (len % 2 == 1) rev.pop_back();
            reverse(rev.begin(), rev.end());
            int pal = stoi(s + rev);
            if (pal <= max && pal >= min) pals.push_back(pal);
        }
    }

    return pals;

}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> list(n);
    for (long long &x : list) cin >> x;
    
    int start{};
    if (m%4 == 1 || m%4 == 2) start = 1;
    if (m%4 == 0 || m%4 == 3) start = 0;
    
    long long s = (long long)(1 + 1.0 * m * (m + 1) / 2);
    int num_0{}, num_1{};
    for (long long x : list) {
        if (x > s) continue;
        if (x <= s) {
            if (start == x%2) {
                num_0++;
            } else {
                num_1++;
            }
        }
    }

    cout << num_0 << " " << num_1 << "\n";
}
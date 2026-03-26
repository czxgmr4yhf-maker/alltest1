#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        long long d = accumulate(a.begin(), a.end(), 0LL) - accumulate(b.begin(), b.end(), 0LL);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (d == 0) {
            cout << 1 << endl;
        } else if(d < 0) {
            int count = 0;
            while(d < 0) {
                d += b[(m--) - 1];
                count++;
            }
            cout << count << endl;
        } else {
            int count = 0;
            while(d > 0) {
                d -= a[(n--) - 1];
                count++;
            }
            cout << count << endl;
        }

    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int m, int n);
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(a[i], a[j]) > 1) {
                    cout << a[i] << " " << a[j] << "\n";
                    return 0;
                }
            }
        }

        cout << -1 << "\n";
    }
}
int gcd(int m, int n) {
    if (n == 0) return m;
    m = m % n;
    return gcd (n, m);
}
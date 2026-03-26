#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> t[i];

    const int maxn = 2000000 + 5;
    static bool lamp[maxn] = {0};
    vector<int> road;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= t[i]; j++) {
        lamp[(int)(a[i] * j)] ^= 1;
        road.push_back((int)(a[i] * j));
        }
    }

    for (int i : road) {
        if(lamp[i]) {
            cout << i << endl; 
            break;
        }
    }

    return 0;
}
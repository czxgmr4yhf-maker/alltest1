#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

const long long INF = LLONG_MAX;
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int g = gcd(a, b);
    vector<long long> dist(a, INF);
    long long cur = 0;
    long long cost = 0;

    for (int i = 0; i < a; i++) {
        if (dist[cur] != INF) break;
        dist[cur] = cost;
        cost += b;
        cur = (cur + b) % a;
    }

    while(n--) {
        long long x;
        cin >> x;

        long long A, B;
        long long s = INF;
        for (int i = 0; i < a; i++) {
            if (dist[i] != INF) {
                long long k = (a + x - dist[i] - 1) / a;
                long long sum = k * a + dist[i];
                if (s > sum) {
                    s = sum;
                    A = k;
                    B = dist[i] / b;
                }
            }
        }

        long long b_ = b / g;
        long long a_ = a / g;
        long long m = A / b_;
        A = A - b_ * m;
        B = B + a_ * m;
        cout << A << " " << B << "\n";
    }
}
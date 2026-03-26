#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &c : a) cin >> c;

        int maxA = a[0];
        int count = 0;
        for (int &c : a) {
            if (c >= maxA) {
                count++;
                maxA = c;
            }
        }

        cout << n - count << '\n';
    }
}
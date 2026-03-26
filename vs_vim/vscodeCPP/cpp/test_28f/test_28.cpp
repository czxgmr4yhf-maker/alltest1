#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n{};
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    set<int> s(arr.begin(), arr.end());
    set<int> counter{};

    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (arr[j] != arr[k]) {
                int sum = arr[j] + arr[k];
                if (s.count(sum)) {
                    counter.insert(sum);
                }
            }
        }
    }

    cout << counter.size() << endl;
}
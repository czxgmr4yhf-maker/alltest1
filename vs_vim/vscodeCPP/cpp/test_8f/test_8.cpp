#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n{};
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        arr.push_back(x);
    }

    for (int j = 0; j < n - 1; j++) {
        for (int k = 0; k < n - 1; k++) {
            int m{};
            if (arr[k] > arr[k + 1]) {
                m = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = m;
            }
        }
    }

    cout << arr[n - 1] - arr[0] << endl;
    
    return 0;
}
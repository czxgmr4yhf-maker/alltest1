#include <iostream> 

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum{};
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    cout << sum << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int l, m;
    cin >> l;
    cin >> m;
    vector<int> treeArry(l + 1, 1);

    while (m-- != 0) {
        int a, b;
        cin >> a;
        cin >> b;
        for (int i = a; i <= b; i++) {
            treeArry[i] = 0;
        }
    }

    int sum{};
    for (int i : treeArry) {
        if (i == 1) sum++;
    }

    cout << sum << endl;
    return 0;
}
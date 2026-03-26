#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Apple {
    int height;
    int cost;
};
int main() {
    int n, s;
    cin >> n >> s;

    int a, b;
    cin >> a >> b;
    int limit = a + b;

    vector<Apple> apples(n);
    int count = 0;
    while(cin >> apples[count].height >> apples[count].cost) {
        count++;
        if (count >= n) break;
    }

    apples.erase(
        remove_if(apples.begin(), apples.end(),
                [limit](const Apple& a) {
                    return a.height > limit;
                }),
        apples.end()
    );

    sort(apples.begin(), apples.end(),
        [](const Apple& a, const Apple& b) {
            return a.cost < b.cost;
        });

    count = 0;
    for (size_t i = 0; i < apples.size(); i++) {
        if (s >= 0) {
            s = s - apples[i].cost;
            count++;
        } else {
            break;
        }
    }

    cout << count << endl;
}
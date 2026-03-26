#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    const int n = 3;
    const int limit = 10;
    vector<int> scores(n);
    for (int &c : scores) cin >> c;

    sort(scores.begin(), scores.end(), 
        [](int a, int b){
            return a < b;
        });

    if (scores[n - 1] - scores[0] >= limit) {
        cout << "check again" << endl;
    } else {
        cout << "final "<<scores[1] << endl;
    }

    return 0;
}
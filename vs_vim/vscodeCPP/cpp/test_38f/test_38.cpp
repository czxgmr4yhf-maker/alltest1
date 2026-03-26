#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int scoreA{}, scoreB{};
    int num, lenA, lenB;
    vector<int> styleA;
    vector<int> styleB;

    cin >> num >> lenA >> lenB;
    int m;
    for (int i = 0; i < lenA; i++) {
        cin >> m;
        styleA.push_back(m);
    }
    for (int i = 0; i < lenB; i++) {
        cin >> m;
        styleB.push_back(m);
    }

    int winOrLoss[5][5] = {
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0}
    };
    int x, y;
    for (int i = 0; i < num; i++) {
        x = i % lenA;
        y = i % lenB;
        scoreA += winOrLoss[styleA[x]][styleB[y]];
        scoreB += winOrLoss[styleB[y]][styleA[x]];
    }

    cout << scoreA << " " << scoreB << endl;
    return 0;
}
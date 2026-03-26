#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int runX[4] = {0, 1, 0, -1};
    int runY[4] = {1, 0, -1, 0};

    int n{};
    cin >> n;
    vector<vector<int>> snackArry(n, vector<int>(n, 0));
    
    int turn{};
    int x = 0;
    int y = 0;
    for (int i = 1; i <= n * n; i++) {
        snackArry[x][y] = i;

        if (i == n * n) break;
        if (x + runX[turn] >= n || y + runY[turn] >= n || x + runX[turn] < 0 || y + runY[turn] < 0) {
            turn = (turn + 1) % 4;
        } else if (snackArry[x + runX[turn]][y + runY[turn]] != 0) {
            turn = (turn + 1) % 4;
        }

        x = x + runX[turn];
        y = y + runY[turn];
    } 

    //input
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            cout << setw(3) << snackArry[j][k];
        }
        cout << '\n';
    }

    return 0;
}
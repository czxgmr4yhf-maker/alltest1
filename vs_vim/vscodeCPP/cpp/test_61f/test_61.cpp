#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> row(m, 0);
    vector<int> col(n, 0);
    vector<vector<int>> mat(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) {
                row[i]++;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            if (mat[i][j] == 1) {
                col[j]++;
            }
        }
    }

    int specialNum{};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) specialNum++;
        }
    }

    cout << specialNum << "\n";
}
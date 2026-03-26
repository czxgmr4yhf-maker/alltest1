#include <iostream>
#include <vector>

using namespace std;

int main() {
    int w, x, h;
    cin >> w >> x >> h;
    vector<vector<vector<int>>> cube(w + 1, vector<vector<int>>(x + 1, vector<int>(h + 1, 0)));

    int q;
    cin >> q;
    int sum = w * x * h;
    while (q-- != 0) {
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;

        int x2, y2, z2;
        cin >> x2 >> y2 >> z2;

        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= x; j++) {
                for (int k = 1; k <= h; k++) {
                    if (i <= x2 && i >= x1 && j <= y2 && j >= y1 && k <= z2 && k >= z1 && cube[i][j][k] == 0) {
                        cube[i][j][k] = 1;
                        sum--;
                    }    
                }
            }
        }
    }

    cout << sum << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int scores[1005][3] = {0};
    
    int n{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            cin >> scores[i][k];
        }
    }

    int num{};
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            int sum1{};
            int sum2{};

            bool dis = true;
            for (int j = 0; j < 3; j++) {
                sum1 += scores[i][j];
                sum2 += scores[k][j];
                if (abs(scores[i][j] - scores[k][j]) > 5) {
                    dis = false;
                    break;
                }
            }

            if (abs(sum1 - sum2) <= 10 && dis) {
                num++;
            }
        }
    }
    cout << num;

    return 0;
}
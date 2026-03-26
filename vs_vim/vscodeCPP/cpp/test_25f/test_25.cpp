#include <iostream>
#include <vector>

using namespace std;

// int main() {
//     int n{};
//     cin >> n;

//     vector<vector<int>> magicSquare(n, vector<int>(n));
//     int x, y;
//     x = 0;
//     y = n / 2;
//     magicSquare[x][y] = 1;
//     for (int i = 2; i <= n*n; i++) {
//         if (x == 0 && y != n - 1) {
//             x = n - 1;
//             y++;
//             magicSquare[x][y] = i;
//             continue;
//         }

//         if (x != 0 && y  == n - 1) {
//             y = 0;
//             x--;
//             magicSquare[x][y] = i;
//             continue;
//         }

//         if (x == 0 && y == n - 1) {
//             x++;
//             y = y;
//             magicSquare[x][y] = i;
//             continue;
//         }

//         if (x != 0 && y != n - 1) {
//             if (magicSquare[x - 1][y + 1] == 0) {
//                 x--, y++;
//                 magicSquare[x][y] = i;
//                 continue;
//             }else {
//                 x++;
//                 y = y;
//                 magicSquare[x][y] = i;
//                 continue;
//             }
//         }
//     }

//     //output
//     for (int j = 0; j < n; j++) {
//         for (int k = 0; k < n ; k++) {
//             cout << magicSquare[j][k] << " ";
//         }
//         cout << '\n';
//     }

//     return 0;
// }

int main() {
    int n;
    cin >> n;
    vector<vector<int>> magicSquare(n, (vector<int>(n, 0)));
    int x = n / 2;
    int y = n - 1;
    magicSquare[x][y] = 1;

    for (int i = 2; i <= n*n; i++) {
        int x1 = (x + 1) % n;
        int y1 = (y + 1) % n;
        if (magicSquare[x1][y1] == 0) {
            magicSquare[x1][y1] = i;
        } else {
            magicSquare[x][(y - 1 +n) % n] = i;
            x1 = x;
            y1 = (y - 1 + n) % n;
        }

        x = x1;
        y = y1;
    }

    for (int j = n - 1; j >= 0; j--) {
        for (int k = 0; k < n; k++) {
            cout << magicSquare[k][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
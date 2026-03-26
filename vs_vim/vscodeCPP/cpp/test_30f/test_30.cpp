#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<vector<int>> total(s1 + s2 + s3 + 1, vector<int>(1, 0));
    for(int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                int sum = i + j + k;
                total[sum][0] += 1;
            }
        }
    } 

    int minSum = 0;
    int frequency = 0;
    for (int i = 3; i <= s1 + s2 + s3; i++) {
        if (total[i][0] > frequency) {                  //Must use ">";
            minSum = i;
            frequency = total[i][0];
        }
    }

    cout << minSum << endl;
    return 0;
}
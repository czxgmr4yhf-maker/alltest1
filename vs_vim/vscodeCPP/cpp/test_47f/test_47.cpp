#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
void permute(vector<int> digits, int i, vector<int>& arr);
int main() {
    int t, n, j, k;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> j >> k;

        string s = to_string(n);
        const char* arry = s.c_str();

        vector<int> digits;
        for (int p = 0; arry[p] != '\0'; p++) {
            digits.push_back(arry[p] - '0');
        }
        
        vector<int> arr;
        permute(digits, 0, arr);
        sort(arr.begin(), arr.end(), 
            [](int a, int b){
                return a < b;
            });
        
        // for (int c : arr) {
        //     cout << c << " ";
        // }
        
        int a = arr[j - 1];
        int b = arr[k -  1];

        string A = to_string(a);
        string B = to_string(b);
        int aNum{}, bNum{};
        for (int m = 0; m <= digits.size() - 1; m++) {
            for (int n = 0; n <= digits.size() - 1; n++) {
                if (m == n && A[m] == B[n]) {
                    aNum++;
                    break;
                }
                if (A[m] == B[n]) {
                    bNum++;
                    break;
                }
            }
        }

        cout << aNum << "A" << bNum << "B" << endl;


    }

    return 0;
}
void permute(vector<int> digits, int i, vector<int>& arr) {
    if (i == digits.size() - 1) {
        int sum{};
        for (int c : digits) {
            sum = sum * 10 + c;
        }
        arr.push_back(sum);
        return;
    }
    for (int j = i; j <= digits.size() - 1; j++) {
        swap(digits[i], digits[j]);
        permute(digits, i+1, arr);
        swap(digits[i], digits[j]);
    }

    return;
}
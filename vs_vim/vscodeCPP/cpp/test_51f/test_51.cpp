#include <iostream>
#include <string>
#include <vector>
using namespace std;

void binShift(string& s) {
    int length = s.size();
    for (int i = length - 1;;) {
        if (s[i] == '0') {
            auto it = s.begin() + i;
            s.erase(it);
            s = "0" + s;
        } else {
            return;
        }
    }
}
int main(){
    int t;
    cin >> t;

    while(t--) {
        int len;
        cin >> len;
        string bin;
        cin >> bin;

        binShift(bin);
        int maxZeros = 0;
        int count{};
        for (char &c : bin) {
            if(c == '1') {
                maxZeros = max(maxZeros, count);
                count = 0;
            }

            if (c == '0') count++;
        }

        cout << maxZeros << '\n';
    }
}
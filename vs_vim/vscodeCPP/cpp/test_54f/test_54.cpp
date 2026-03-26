#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void sArr(string s, vector<string>& stringArr) {
    string ss = "";
    for (char &c : s) {
        if (islower(c)) {
            ss += c;
        } else if (c == 'B') {
            auto it = ss.end() - 1;
            ss.erase(it);
        } else if(c == 'P') {
            stringArr.push_back(ss);
        }
    }
}
int main() {
    string s;
    cin >> s;

    vector<string> stringArr;
    stringArr.push_back(" ");
    sArr(s, stringArr);

    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;

        string tail = stringArr[x];
        int len = (int)tail.size();
        int count = 0;
        for (int pos = 0; pos <= (int)(stringArr[y].size()) - len; pos++) {
            if (stringArr[y].substr(pos, len) == tail) count++;
        }
        cout << count << '\n';
    }
}
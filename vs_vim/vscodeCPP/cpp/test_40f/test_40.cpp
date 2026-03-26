#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void modify(string &s, int p1, int p2, int p3, int i);
bool isSameType(char a, char b);
int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    string s;
    cin >> s;

    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '-' && isSameType(s[i - 1], s[i + 1]) && s[i + 1] != '\0'){
            if (s[i + 1] - s[i - 1] > 1) {
                modify(s, p1, p2, p3, i);
            }else if(s[i + 1] - s[i - 1] == 1) {
                s.erase(i, 1);
            }
        } 
    }

    cout << s;
    return 0;
}
void modify(string &s, int p1, int p2, int p3, int i) {
    char left = s[i - 1];
    char right = s[i + 1];
    string fill;

    for (char c = left + 1; c < right; c++) {
        char ch;
        if(p1 == 3) ch = '*';
        else if(isdigit(c)) ch = c;
        else if(p1 == 1) ch = c;
        else if(p1 == 2) ch = toupper(c);

        for (int k = 0; k < p2; k++) {
            fill += ch;
        }
    }

    if (p3 == 2) {
        reverse(fill.begin(), fill.end());
    }

    s.replace(i, 1, fill);
}

bool isSameType(char a, char b) {
    return ((isdigit(a) && isdigit(b)) || (islower(a) && islower(b)));
}
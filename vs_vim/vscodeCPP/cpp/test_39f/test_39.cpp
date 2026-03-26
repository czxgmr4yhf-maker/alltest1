#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s, line;
    while (cin >> line) {
        s += line;
        if(line.find('E') != string::npos) break;
    }

    int x{}, y{};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'W') {
            x++;
        } else if (s[i] == 'L') {
            y++;
        } else if(s[i] == 'E') {
            break;
        }

        if ((x >= 11 || y >= 11) && abs(x - y) >= 2) {
            cout << x << ":" << y << endl;
            x = 0; y = 0;
        }  

    }

    cout << x << ":" << y << endl;
    cout << '\n';
    x = 0; y = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'W') {
            x++;
        } else if (s[i] == 'L') {
            y++;
        } else if(s[i] == 'E') {
            break;
        }

        if ((x >= 21 || y >= 21) && abs(x - y) >= 2) {
            cout << x << ":" << y << endl;
            x = 0; y = 0;
        }  

    }

    cout << x << ":" << y << endl;
    return 0;
}
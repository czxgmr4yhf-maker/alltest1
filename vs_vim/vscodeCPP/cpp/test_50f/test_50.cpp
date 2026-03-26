#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int l, a, b;
        cin >> l >> a >> b;

        int pointer = a;
        int maxnum = a;
        while (1 == 1) {
            pointer = (pointer + b) % l;
            maxnum = max(maxnum, pointer);
            if(pointer == a) break;
        }

        cout << maxnum << '\n';
    }
}
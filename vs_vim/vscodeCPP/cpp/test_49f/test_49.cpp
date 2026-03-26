#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--) {
        int n{};
        cin >> n;

        vector<string> ss(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ss[i];
        }

        string sNew = ss[1];
        for (int i = 2; i <= n; i++) {
            if (sNew + ss[i] >= ss[i] + sNew) sNew = ss[i] + sNew;
            else sNew = sNew + ss[i];
        }
        
        cout << sNew << '\n';
    }
}
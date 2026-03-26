#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> colors(n);
        for(int &c : colors) cin >> c;

        set<int> colorTypes;
        for (int &c : colors) colorTypes.insert(c);

        int a = (int)colorTypes.size();
        while(1 == 1) {
            a = (int)colorTypes.size();
            if(colorTypes.count(a)) {
                break;
            } else {
                colorTypes.insert(a);
            }
        }

        cout << a << '\n';
    }
}
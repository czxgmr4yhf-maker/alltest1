#include <iostream>
using namespace std;

int main() {
    const int list = 7;
    int awardArry[7] = {0};
    int n{};
    cin >> n;

    int prize[8] = {0};
    for (int i = 0; i < list; i++) {
        cin >> prize[i];
    }                               //get the winning numbers

    while (n-- != 0) {
        int prizeRank = 7;                  //determine the winning level each times
        for (int i = 0; i < list; i++) {
            int x{};
            cin >> x;
            
            for (int m : prize) {
                if (x == m) {
                    prizeRank--;
                }
            }
        }
        awardArry[prizeRank]++;
    }

    for (int i = 0; i < list; i++) {
        cout << awardArry[i] << " "; //output the award information
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int n{};
    cin >> n;

    vector<int> score;
    for (int i = 0; i < n; i++) {
        int x{};
        cin >> x;
        
        score.push_back(x);
    }

    //search the biggest number
    int maxNum = score[0];
    for (int i = 0; i < score.size(); i++) {
        if (score[i] > maxNum) {
            maxNum = score[i];
        }
    }
    
    //search the smallest number
    int minNum = score[0];
    for (int i = 0; i < score.size(); i++) {
        if (score[i] < minNum) {
            minNum = score[i];
        }
    }
    
    //get the score
    int sum{};
    for (int i = 0; i < score.size(); i++) {
        sum += score[i];
    }
    
    double factor = pow(10.0, 2);
    double grades = round(((sum - minNum - maxNum) / (double)(n - 2)) * factor) / factor;
    cout << fixed << setprecision(2) << grades << endl;

    return 0;
}
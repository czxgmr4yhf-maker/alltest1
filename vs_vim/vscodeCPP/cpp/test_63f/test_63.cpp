#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numSize{};
    int k;
    cin >> numSize >> k;

    vector<int> nums(numSize);
    for (int &c : nums) cin >> c;

    while(k--) {
        int c = nums[numSize - 1];
        nums.pop_back();
        nums.insert(nums.begin(), c); 
    }                   //算法复杂度为O(k*numSize),空间复杂度为O(numSize)

    for (int &c : nums) {
        cout << c << " ";
    }

    cout << "\n";
}
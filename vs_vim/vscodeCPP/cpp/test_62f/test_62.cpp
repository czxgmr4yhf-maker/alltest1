#include <iostream>
#include <vector>
#include <string>
using namespace std;

void creatHappyList(string& s, vector<string>& happyList, vector<string> strStand, const int k) {
    if (s.length() == k) {
        happyList.push_back(s);
        return;
    }

    for (int i = 1; i < 4; i++) {
        if (strStand[i] == strStand[0]) continue;

        s += strStand[i];
        strStand[0] = strStand[i];
        creatHappyList(s, happyList, strStand, k);
        s.pop_back(); 
    }
}       //在将s添加进数组之后，将s初始化，另外，通过循环加递归来生成快乐字符，同时按照字典排序
int main() {
    int n, k;
    cin >> n >> k;

    vector<string> strStand = {NULL, "a", "b", "c"};
    vector<string> happyList;
    string s =  "";

    
}
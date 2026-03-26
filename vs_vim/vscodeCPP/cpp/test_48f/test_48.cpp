#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这是一个逻辑正确，且方便你在本地手动测试的版本
// 去掉了加速流，这样你每输入一行，它就会立刻回车输出结果
int main() {
    int t;
    if (!(cin >> t)) return 0; // 读取测试用例数量

    while (t--) {
        int n;
        cin >> n; // 读取数组长度
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i]; // 读取数组元素
        }

        // 单调栈逻辑
        vector<int> st; 

        for (int x : p) {
            int current_min = x;
            
            // 如果栈顶元素比当前 x 小，说明 x 可以把栈顶的连通块“连”起来
            // 只要满足条件，就一直合并
            while (!st.empty() && st.back() < x) {
                current_min = min(current_min, st.back());
                st.pop_back();
            }
            // 将合并后的新连通块（以最小值为代表）压入栈
            st.push_back(current_min);
        }

        // 如果最后栈里只剩下一个连通块，说明全连通了
        if (st.size() == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
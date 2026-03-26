#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // 系数矩阵 A
    double A[3][3] = {
        {2, 1, 1},
        {1, 1, 1},
        {1, 1, 2}
    };
    // 常数项 b
    double b[3] = {0, 3, 1};

    // 初始向量 x^(0) = (0,0,0)
    vector<double> x(3, 0.0);
    vector<double> x_new(3, 0.0);

    double tol = 0.5e-3; // 精度要求
    int maxIter = 1000;  // 最大迭代次数
    int k = 0;

    cout << fixed << setprecision(6);
    cout << "迭代过程:" << endl;

    while (k < maxIter) {
        // 高斯-赛德尔迭代
        x_new[0] = (b[0] - A[0][1]*x[1] - A[0][2]*x[2]) / A[0][0];
        x_new[1] = (b[1] - A[1][0]*x_new[0] - A[1][2]*x[2]) / A[1][1];
        x_new[2] = (b[2] - A[2][0]*x_new[0] - A[2][1]*x_new[1]) / A[2][2];

        // 计算无穷范数差
        double diff = 0.0;
        for (int i = 0; i < 3; i++) {
            diff = max(diff, fabs(x_new[i] - x[i]));
        }

        // 输出本次迭代
        cout << "迭代 " << k+1 << ": ";
        for (int i = 0; i < 3; i++) cout << x_new[i] << " ";
        cout << " ||差||∞ = " << diff << endl;

        if (diff <= tol) break; // 满足精度要求则停止

        x = x_new; // 更新
        k++;
    }

    cout << "\n最终解 (迭代 " << k+1 << " 次): ";
    for (int i = 0; i < 3; i++) cout << x_new[i] << " ";
    cout << endl;

    return 0;
}
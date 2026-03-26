#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

struct SplineSeg {
    double a, b, c, d, x; // 多项式系数: S(x) = a + b*(t) + c*(t^2) + d*(t^3), t=x-x_i
};

// 这里是专门针对 n=2 (三个点) 的clamped cubic spline
int main() {
    vector<double> x = {2.5, 7.5, 10.0};
    vector<double> y = {4.0, 7.0, 5.0};
    double fp0 = 0.13;   // f'(2.5)
    double fpn = -0.13;  // f'(10)

    int n = x.size();
    vector<double> h(n-1);
    for(int i=0;i<n-1;i++) h[i] = x[i+1]-x[i];

    // 构建三对角方程 A*M = rhs, M是二阶导
    vector<double> A(n*n,0.0), rhs(n,0.0);

    // Clamped 边界条件
    A[0*n+0] = 2*h[0];
    A[0*n+1] = h[0];
    rhs[0] = 6.0*((y[1]-y[0])/h[0] - fp0);

    A[(n-1)*n+(n-2)] = h[n-2];
    A[(n-1)*n+(n-1)] = 2*h[n-2];
    rhs[n-1] = 6.0*(fpn - (y[n-1]-y[n-2])/h[n-2]);

    // 中间点
    for(int i=1;i<n-1;i++){
        A[i*n+(i-1)] = h[i-1];
        A[i*n+i]     = 2*(h[i-1]+h[i]);
        A[i*n+(i+1)] = h[i];
        rhs[i] = 6.0*((y[i+1]-y[i])/h[i] - (y[i]-y[i-1])/h[i-1]);
    }

    // 高斯消元解 M
    vector<double> M = rhs;
    // 简单高斯消元
    for(int i=0;i<n;i++){
        // pivot
        double piv = A[i*n+i];
        for(int j=i;j<n;j++) A[i*n+j] /= piv;
        M[i] /= piv;
        for(int k=i+1;k<n;k++){
            double factor = A[k*n+i];
            for(int j=i;j<n;j++) A[k*n+j] -= factor*A[i*n+j];
            M[k] -= factor*M[i];
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            M[i] -= A[i*n+j]*M[j];
        }
    }

    // 输出二阶导
    cout << "M (second derivatives at nodes):\n";
    for(int i=0;i<n;i++) cout << "M["<<i<<"] = " << M[i] << endl;

    // 生成每段多项式系数
    vector<SplineSeg> segs;
    for(int i=0;i<n-1;i++){
        double hi = h[i];
        SplineSeg s;
        s.x = x[i];
        s.a = y[i];
        s.b = (y[i+1]-y[i])/hi - (2*M[i]+M[i+1])*hi/6.0;
        s.c = M[i]/2.0;
        s.d = (M[i+1]-M[i])/(6.0*hi);
        segs.push_back(s);
    }

    // 打印每段多项式
    cout << fixed << setprecision(6);
    for(int i=0;i<segs.size();i++){
        auto s=segs[i];
        cout << "Interval ["<<x[i]<<","<<x[i+1]<<"] :\n";
        cout << "S(x) = "<<s.a<<" + "<<s.b<<"*(t) + "<<s.c<<"*(t^2) + "<<s.d<<"*(t^3), t=(x-"<<s.x<<")\n";
    }


        std::ofstream fout("spline.dat");
    for (int i=0; i<segs.size(); i++) {
        double xi = x[i], xi1 = x[i+1];
        for (double X=xi; X<=xi1; X+=0.01) {
            double t = X - segs[i].x;
            double Y = segs[i].a + segs[i].b*t + segs[i].c*t*t + segs[i].d*t*t*t;
            fout << X << " " << Y << "\n";
        }
    }
    fout.close();

    std::cout << "已生成 spline.dat 文件，可用 Python 绘图\n";

    return 0;
}
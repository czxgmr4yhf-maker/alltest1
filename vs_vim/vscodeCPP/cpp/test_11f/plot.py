import matplotlib.pyplot as plt

# 读取插值曲线数据
x_curve, y_curve = [], []
with open("spline.dat") as f:
    for line in f:
        X, Y = map(float, line.split())
        x_curve.append(X)
        y_curve.append(Y)

# 原始数据点 (跟 C++ 保持一致)
x_data = [2.5, 7.5, 10.0]
y_data = [4.0, 7.0, 5.0]

plt.plot(x_curve, y_curve, label="Cubic Spline")
plt.scatter(x_data, y_data, color="red", zorder=5, label="Data Points")
plt.xlabel("x")
plt.ylabel("y")
plt.title("Clamped Cubic Spline (from C++ output)")
plt.legend()
plt.grid(True)
plt.show()
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

vector<int> getmedianArry(int median, vector<int> nums1, vector<int> nums2);

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> nums1;
    for (int i = 0; i < m; i++) {
        int x{};
        cin >> x;
        nums1.push_back(x);
    }

    vector<int> nums2;
    for (int i = 0; i < n; i++) {
        int x{};
        cin >> x;
        nums2.push_back(x);
    }

    if((m + n) % 2 == 0) {
        int median = (m + n) / 2;
        vector<int> nums3 = getmedianArry(median, nums1, nums2);
        cout << fixed << setprecision(5) << (nums3[median - 1] + nums3[median]) / 2.0 << endl;
    } else {
        int median = (m + n) / 2;
        vector<int> nums3 = getmedianArry(median, nums1, nums2);
        cout << fixed << setprecision(5) << (float)nums3[median] << endl;
    }

    return 0;
}

vector<int> getmedianArry(int median, vector<int> nums1, vector<int> nums2) {
    vector<int> nums3;
    int j{}, k{};
    while (nums3.size() < median + 1) {
        if (k >= nums2.size()) {
            nums3.push_back(nums1[j++]);
        } else if (j >= nums1.size()) {
            nums3.push_back(nums2[k++]);
        } else {
            if (nums1[j] <= nums2[k]) {
                nums3.push_back(nums1[j++]);
            } else {
                nums3.push_back(nums2[k++]);
            }
        }
    }

    return nums3;
}
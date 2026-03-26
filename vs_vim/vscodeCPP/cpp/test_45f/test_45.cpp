#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> fa;
    DSU(int n): fa(n + 1) {
        for(int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        fa[b] = a;
        return true;
    }
};
int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<struct Edge> preparedEdges;
    vector<pair<int, int>>curr, prev;
    for (int i = n; i >= 1; i--) {
        curr.clear();
        curr.push_back({p[i], i});
        // cout << "i = " << i << "," << "p[" << i << "] = " << p[i] << '\n';


        for (auto &pr : prev) {
            int g2 = gcd(p[i], pr.first); 
            if (g2 != curr.back().first || g2 != pr.first) {
                preparedEdges.push_back({i, pr.second, g2});
            }

            curr.push_back({g2, pr.second});
        }

        prev = curr;
        // for (auto &c : prev){
        //     cout << "{" << c.first << " " << c.second << "}" << '\t';
        // }
        // cout <<'\n';
    }


    // for (auto &c : preparedEdges){
    //     cout << "{" << c.u << " " << c.v << " " << c.w << "}" << '\t';
    // }
    // cout << '\n';

    for (int i = 1; i <= n - 1; i++) {
        preparedEdges.push_back({i, i + 1, gcd(p[i], p[i + 1])});
    }

    sort(preparedEdges.begin(), preparedEdges.end(),
        [](auto &a, auto&b) {
            return a.w < b.w;
        });

    DSU dsu(n);
    long long ans = 0;
    int used = 0;

    // for (auto &c : preparedEdges){
    //     cout << "{" << c.u << " " << c.v << " " << c.w << "}" << '\t';
    // }
    // cout << '\n';

    for (auto &e : preparedEdges) {
        if (dsu.unite(e.u, e.v)) {
            ans += e.w;
            // cout << "{" << e.u << " " << e.v << " " << e.w << "}" << '\t';
            if (++used == n - 1)
                break;
        }
    }

    // cout << '\n';
    cout << ans << endl;
}
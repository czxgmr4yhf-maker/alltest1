#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n + 1);
    int cityProduct[n + 1];
    for (int i = 1; i < n + 1; i++) {
        cin >> cityProduct[i]; 
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> productDistance(k + 1, 0);
    vector<int> dist(n+1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i < dist.size(); i++) {
        productDistance[cityProduct[i]] = max(productDistance[cityProduct[i]], dist[i]);
    }

    for (int i = 1; i < k + 1; i++) {
        cout << productDistance[i] << (i == k ? '\n' : ' ');
    }
}
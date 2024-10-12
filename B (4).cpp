#include "bits/stdc++.h"
 
using namespace std;
 
// const int mod = 998244353;
#define int long long

void solve() {
 
    int n;
    cin >> n;
    std::vector<vector<int>> values(n), args(n);
    vector<int> dist(n);
    vector<int> leaf;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        values[i].resize((1 << x));
        if (x == 0) {
            leaf.push_back(i);
            continue;
        }
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            y--;
            args[i].push_back(y);

        }
        for (int j = 0; j < (1 << x); j++) {
            cin >> values[i][j];
        }
    }
    int mx = 0;
    function<void(int)> f = [&](int v) {
        mx = max(mx, dist[v]);
        for (int u : args[v]) {
            dist[u] = dist[v] + 1;
            f(u);
        }
    };

    function<int(int)> get = [&](int v) {
        int cur = 0;
        for (int u : args[v]) {
            cur = cur * 2 + get(u);
        }
        return values[v][cur];
    };

    f(n - 1);
    cout << mx << endl;
    int k = leaf.size();
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            values[leaf[k - 1 - j]][0] = (i >> j & 1);
        }
        cout << (char) ('0' + get(n - 1));
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
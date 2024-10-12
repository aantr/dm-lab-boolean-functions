#include "bits/stdc++.h"
 
using namespace std;
 
// const int mod = 998244353;
#define int long long

void solve() {
 
    int n;
    cin >> n;
    std::vector<int> v(1 << n);
    vector<int> blocks;
    int cur = n;
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << n); i++) {
        string s;
        cin >> s;
        cin >> v[i];
        if (v[i] == 1) {
            int res = -1;
            for (int j = 0; j < n; j++) {
                int c = j + 1;
                if (s[j] - '0' == 0) {
                    ans.push_back({1, j + 1});   
                    cur++;
                    c = cur;
                }
                if (j != 0) {
                    ans.push_back({2, res, c});   
                    cur++;
                    res = cur;
                } else {
                    res = c;
                }
            }
            blocks.push_back(res);
        }
    }
    if (blocks.size() == 0) {
        cout << cur + 2 << endl;
        cout << "1 1\n";
        cout << "2 1 " << cur + 1;
        return;
    }
    int res = blocks[0];
    for (int i = 1; i < blocks.size(); i++) {
        ans.push_back({3, res, blocks[i]});
        cur++;
        res = cur;
    }

    cout << cur << endl;
    for (auto i : ans) {for (int j : i) cout << j << " "; cout << "\n";}

}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
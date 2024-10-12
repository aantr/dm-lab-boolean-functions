#include "bits/stdc++.h"
 
using namespace std;

// const int mod = 998244353;
// #define int long long

void solve() {

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int _ = 0; _ < 101; _++)
    for (int i = 0; i < a.size(); i++) {
        if (accumulate(a[i].begin(), a[i].end(), 0) == -n) {
            cout << "YES\n";
            return;
        }

        vector<array<int, 2>> cnt;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                cnt.push_back({j, 0});
            } else if (a[i][j] == 1) {
                cnt.push_back({j, 1});
            }
        }
        if (cnt.size() == 1) {
            vector<vector<int>> new_a;
            for (int j = 0; j < a.size(); j++) {
                if (a[j][cnt[0][0]] == cnt[0][1]) {
                    
                } else {
                    a[j][cnt[0][0]] = -1;
                    new_a.push_back(a[j]);
                }
            }
            a = new_a;
        }

        
    }
    
    cout << "NO\n";


}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
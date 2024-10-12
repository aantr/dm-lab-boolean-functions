#include "bits/stdc++.h"
 
using namespace std;
 
// const int mod = 998244353;
#define int long long

void solve() {

    int n;
    cin >> n;
    std::vector<int> v(1 << n);
    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        string s;
        cin >> s;
        cin >> a[i];
        cout << s << " ";
        int x = 0;
        for (int j = 0; j < i; j++) {
            if ((i & j) == j) {
                x ^= v[j];
            }
        }
        v[i] = x ^ a[i];
        cout << v[i] << "\n";
    }


}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
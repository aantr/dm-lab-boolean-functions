#include "bits/stdc++.h"
 
using namespace std;
 
// const int mod = 998244353;
#define int long long
 
bool t0(string a, int s) {
    return a[0] - '0' == 0;
}
 
bool t1(string a, int s) {
    return a[(1 << s) - 1] - '0' == 1;
}
 
bool sim(string a, int s) {
    for (int i = 0; i < (1 << s); i++) {
        if (a[i] == a[i ^ ((1 << s) - 1)]) {
            return false;
        }
    }
    return true;
}
 
bool m(string a, int s) {
    for (int i = 0; i < (1 << s); i++) {
        for (int j = 0; j < (1 << s); j++) {
            if (i == (i & j)) { // j >= i
                if (a[i] > a[j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool l(string a, int s) {
    vector<int> p(s);
    int one = a[0] - '0';
    for (int i = 0; i < s; i++) {
        p[i] = (a[0] - '0') ^ (a[1 << i] - '0');
        // cout << p[i] << " ";
    }
    // cout << endl;
    for (int i = 0; i < (1 << s); i++) {
        int v = one;
        for (int j = 0; j < s; j++) {
            v ^= (i >> j & 1) & p[j];
        }
        if (v != a[i] - '0') {
            return false;
        }
    }
    return true;
}
 
 
void solve() {
 
    int n;
    cin >> n;
    std::vector<int> post(5, 0);
 
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        string a;
        cin >> a;
        post[0] |= !t0(a, s);
        post[1] |= !t1(a, s);
        post[2] |= !sim(a, s);
        post[3] |= !m(a, s);
        post[4] |= !l(a, s);
    }
 
    if (accumulate(post.begin(), post.end(), 0) == 5) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
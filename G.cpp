#include "bits/stdc++.h"
    
using namespace std;
#define int long long
#define TIME (long double) clock() / CLOCKS_PER_SEC
  
int band(int x, int y) {
    return x & y;
}
  
int bor(int x, int y) {
    return x | y;
}
  
int bnot(int x) {
    int c = 60;
    return x ^ ((1ll << c) - 1);
}
  
void solve() {
   
    int n;
    cin >> n;
    map<int, string> v;
     
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        v[stoll(x)] = to_string(i + 1);
    }
 
    int need;
    cin >> need;
  
    map<int, string> cur;
    vector<bool> correct(32);
    vector<array<int, 2>> OP;
    queue<pair<int, string>> q;
   
    function<void(int, string)> add = [&](int v, string s) {
        if (cur.size() > 1e6) { // ml
            return;
        }
        if (cur.count(v)) {
            return;
        }
  
        cur[v] = s;
  
        if (cur.count(bnot(v)) == 0) {
            q.push({bnot(v), "(~" + s + ")"});
        }
        for (auto i : cur) {
            int q1 = band(i.first, v);
            int q2 = bor(i.first, v);
            if (cur.count(q1) == 0) {
                q.push({q1, "(" + i.second + "&" + s + ")"});
            }
            if (cur.count(q2) == 0) {
                q.push({q2, "(" + i.second + "|" + s + ")"});
            }
        }
    };
    
    for (auto i : v) {
        add(i.first, i.second);
    }

    while (!q.empty()) {
        auto el = q.front();
        q.pop();
        add(el.first, el.second);
        if (cur.size() > 1e6 || q.size() > 1e6) {
            break;
        }
    }

    for (int i = 0; i < 40; i++) {
        for (auto j : cur) {
            int v = j.first;   
            bool ok_and = band(need, v) == need, ok_or = bor(need, v) == need;
            int cnt_and = 0, cnt_or = 0;
            for (int i = 0; i < 32; i++) {
                cnt_and += !correct[i] && ((v >> i & 1) == 0);
                cnt_or += !correct[i] && ((v >> i & 1) == 1);
            }
            if (ok_or && cnt_or > 0) {
                for (int i = 0; i < 32; i++) {
                    if (v >> i & 1) correct[i] = 1;
                }
                OP.push_back({v, 0});
                break;
            }
            if (ok_and && cnt_and > 0) {
                for (int i = 0; i < 32; i++) {
                    if ((v >> i & 1) == 0) correct[i] = 1;
                }
                OP.push_back({v, 1});
                break;
            }
        }
    }

    assert(OP.size() <= 32);

    if (accumulate(correct.begin(), correct.end(), 0) == 32) {
        int prev = -1;
        string ans;
        // restore answer
        reverse(OP.begin(), OP.end());
        for (int j = 0; j < 2; j++)
        for (auto i : OP) {
            if (i[1] != j) {
                continue;
            }
            if (prev == -1) {
                prev = i[0];
                ans = cur[i[0]];
                continue;
            }
            if (i[1] == 0) {
                prev = bor(prev, i[0]);
                ans = "(" + ans + "|" + cur[i[0]] + ")";
            } else {
                prev = band(prev, i[0]);
                ans = "(" + ans + "&" + cur[i[0]] + ")";
            }
            // cout << ans << " " << prev << "\n";
        }
        cout << ans << "\n";
    } else {
        cout << "Impossible\n"; 
    }
   
    // if (cur.count(need)) {
    //     cout << cur[need] << "\n";    
    // } else {
    //     cout << "Impossible\n"; 
    // }
   
}
    
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
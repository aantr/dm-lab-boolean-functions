#include "bits/stdc++.h"
 
using namespace std;

#define int long long

string nott(string x) {
    return "(" + x + ")|(" + x + ")";
}

string andd(string x, string y) {
    return nott("" + x + "|" + y + "");
}

string orr(string x, string y) {
    return nott(andd(nott(x), nott(y)));
}


string s(int n) {
    if (n == 1) {
        return "(" + andd("A" + to_string(n - 1), "B" + to_string(n - 1)) + ")";
    }
    string x = to_string(n - 1);
    return "((" + s(n - 1) + "|((A" + x + "|A" + x  + ")|(B" + x + "|B" + x + ")))|(A" + x + "|B" + x + "))";
}

void solve() {

    int n;
    cin >> n;
    cout << s(n);

}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include "bits/stdc++.h"

using namespace std;

// const int mod = 998244353;
#define int long long

vector<int> s(vector<vector<int>> &a) {
	int n = a.size();
	vector<int> ans(5, 1);
	for (int i = 0; i < n; i++) {
		ans[0] &= a[i][i] == 1;
	}
	for (int i = 0; i < n; i++) {
		ans[1] &= a[i][i] != 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[2] &= a[i][j] == a[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[3] &= i == j || a[i][j] <= !a[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ans[4] &= (a[i][j] && a[j][k]) <= a[i][k];
			}
		}
	}
	return ans;
}

void solve() {

	int n;
	cin >> n;
	std::vector<vector<int>> a(n, vector<int> (n)), b(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j  = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j  = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
	for (int i : s(a)) cout << i << " "; cout << '\n';
	for (int i : s(b)) cout << i << " "; cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int v = 0;
			for (int k = 0; k < n; k++) {
				if (a[i][k] && b[k][j]) {
					v = 1;
				}
			}
			cout << v << " ";
		}
		cout << "\n";
	}

}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
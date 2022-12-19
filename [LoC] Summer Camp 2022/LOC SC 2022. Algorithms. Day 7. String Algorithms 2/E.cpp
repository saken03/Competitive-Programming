/***
    AUTHOR:    shabylkhan
    CREATED:   26.07.2022 16:07:28

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> kmp(vector<int> s) {
	int n = (int)s.size();
 	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < (int)s.size(); i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}


void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> p = kmp(a);
	for (int i : p) cout << i << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
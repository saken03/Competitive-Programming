/***
    AUTHOR:    shabylkhan
    CREATED:   28.10.2022 17:11:41

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	bool u[26][26];
	int m[26];


	m[a[0] - 'a'] = 1;
	for (int i = 1; i < n; i++) {
		u[a[i - 1] - 'a'][a[i] - 'a'] = 1;
		m[a[i] - 'a']++;
	}
	u[a[n - 1] - 'a'][a[0] - 'a'] = 1;

	if (!m[b[0] - 'a']) {
		cout << "NO\n";
		return;
	}           

	char c = b[0];

	for (int i = 1; i < (int)b.size(); i++) {
		if (!u[c - 'a'][b[i] - 'a'] || (c == b[i] && m[c - 'a'] == 1)) {
			cout << "NO\n";
			return;
		}
		c = b[i];
	}
	cout << "YES\n";
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
/***
    AUTHOR:    shabylkhan
    CREATED:   20.10.2022 20:37:29

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, bool> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		m[x] = 1;
	}

	cout << ((int)m.size() == 2 ? n / 2 + 1 : n) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 
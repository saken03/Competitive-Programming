/***
    AUTHOR:    shabylkhan
    CREATED:   13.10.2022 20:59:31

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int m, s;
	cin >> m >> s;   
	vector<bool> u(105);
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		u[x] = 1;
	}
	bool ok = 1;
	int i = 1;
	for (; s; i++) {
		if (!u[i]) {
			s -= i;
			u[i] = 1;
		}
	}
	if (s < 0) ok = 0;
	while (u[i]) i++;
	for (int j = i + 1; j < 100; j++) if (u[j]) ok = 0;
	cout << (ok ? "YES" : "NO") << '\n';
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

/***
    AUTHOR:    shabylkhan
    CREATED:   08.06.2022 21:22:22

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	bool ok = 0;
	int x;
	cin >> x;
	int mn = x, mx = x;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		if (mn < x && x < mx) ok = 1;
		mn = min(mn, x);
		mx = max(mx, x);
	}	
	cout << (!ok ? "yes" : "no") << '\n';
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
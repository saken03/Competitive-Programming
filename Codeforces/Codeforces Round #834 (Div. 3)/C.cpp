/***
    AUTHOR:    shabylkhan
    CREATED:   13.10.2022 20:59:31

***/

#include<bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
	ll l, r, x, a, b;
	cin >> l >> r >> x >> a >> b;

	if (a > b) swap(a, b);

	if (a == b) cout << 0;
	else if (a + x <= b) {
		cout << 1;
	}
	else if (b + x <= r || a - x >= l) {
		cout << 2;
	}
	else if (a + x <= r && r - x >= l && l + x <= b) {
		cout << 3;
	}
	else cout << -1;
	cout << '\n';
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

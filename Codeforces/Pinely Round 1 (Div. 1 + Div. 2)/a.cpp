/***
    AUTHOR:    shabylkhan
    CREATED:   20.10.2022 20:37:29

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	cout << (a + b + 2 <= n ? "YES" : "NO") << '\n';
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
/***
    AUTHOR:    shabylkhan
    CREATED:   08.06.2022 20:57:16

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int x, y, a;
	cin >> x >> y >> a;
	cout << (x <= a && a < y ? "YES" : "NO") << '\n';	
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
/***
    AUTHOR:    shabylkhan
    CREATED:   08.06.2022 21:00:15

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	cout << ((a + b) % 2 == 0 ? "YES" : "NO") << '\n';	
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
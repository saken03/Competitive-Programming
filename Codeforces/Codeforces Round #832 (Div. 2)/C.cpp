/***
    AUTHOR:    shabylkhan
    CREATED:   04.11.2022 22:26:37

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	long long mn = 1e10;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i] + 0ll);
	}
	
	for (int i = 0; i < n; i++) {
		a[i] -= mn;
	}

	if (a[0] == 0) cout << "Bob\n";
	else cout << "Alice\n";
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
/***
    AUTHOR:    shabylkhan
    CREATED:   08.06.2022 21:03:30

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += (a[i] > 0 ? 1 : -1);
	}	
	if (n & 1) {
		cout << -1 << '\n';
		return;
	}

	cout << abs(cnt) / 2 << '\n';
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
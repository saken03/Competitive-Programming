/***
    AUTHOR:    shabylkhan
    CREATED:   16.06.2022 21:33:10

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << (a[0] == 0 ? "YES\n" : "NO\n");
		return;
	}

	vector<int> on(n), sol(n);

	on[0] = a[0];

	if (a[i] <= 0) {
		cout << "NO\n";
		return;
	}

	for (int i = 1; i < n - 1; i++) {
		
	}
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
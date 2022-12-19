/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 14:47:05

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	a[n] = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cur = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) {
			cur++;
		}
		else {
			cout << cur << ' ' << a[i] << ' ';
			cur = 1;
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 
/***
    AUTHOR:    shabylkhan
    CREATED:   14.06.2022 21:27:45

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;

	vector<int> a(n), pos;
	int sum = 0;
	pos.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		pos.push_back(i + 1);
	}

	if (sum < s) {
		cout << -1;
		return;
	}
	if (sum == s) {
		cout << 0;
		return;
	}

	int need = sum - s, ans = 1e9;
	for (int i = 0; i <= need; i++) {
		ans = min(ans, pos[i] + n - pos[sum + 1 - i] + 1);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
		cout << '\n';
	}

	return 0;
} 
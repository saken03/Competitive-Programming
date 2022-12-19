/***
    AUTHOR:    shabylkhan
    CREATED:   28.07.2022 16:29:11

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int mx = 0;
	vector<int> a(200500);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		a[l]++;
		a[r + 1]--;
		mx = max(mx, r);
	}
	// 1 2 2 2 2 1 0
	int mx2 = 0, ans = 0, cnt = 0;
	for (int i = 1; i <= mx + 1; i++) {
		a[i] += a[i - 1];
		mx2 = max(mx2, a[i]);
		if (a[i] == 0) {
			ans += 1;
			cnt += mx2;
			mx2 = 0;
			continue;
		}
	}
	cnt += mx2;
	cout << ans + n - cnt<< '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
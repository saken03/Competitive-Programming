/***
    AUTHOR:    shabylkhan
    CREATED:   28.07.2022 15:54:48

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> seg(n);
	for (int i = 0; i < n; i++) {
		cin >> seg[i].second >> seg[i].first;
	}
	sort(seg.begin(), seg.end());
	int ans = 0, lastr = 0;
	for (int i = 0; i < n; i++) {
		int l = seg[i].second;
		int r = seg[i].first;
		if (lastr <= l) {
			ans++;
			lastr = r;
		}
	}
	cout << ans << '\n';
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
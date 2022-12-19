/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 21:39:25

***/

#include<bits/stdc++.h>

using namespace std;

int n;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) {
		return 1;
	}
	else {                           
		// i, j  - 1
		// n - 1 - i, j
		int l = min(a.second, b.second);
		int r = min(n - a.second, n - b.second);
		if (l < r) {
			if (a.second < b.second) {
				return 1;
			}
			return 0;
		}
		else {
			if (n - a.second < n - b.second) {
				return 1;
			}
			return 0;
		}
	}
}

void solve() {
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int need = (n - 1) / 2;
	vector<pair<int, int>> cool;
	for (int i = 1; i < n - 1; i++) {
		int mx = max(a[i - 1], a[i + 1]);
		if (mx < a[i]) cool.push_back({0, i});
		else cool.push_back({mx - a[i] + 1, i});
	}
	sort(cool.begin(), cool.end(), comp);
	int ans = 0;

	while (need) {
		for (int i = 0; i < (int)cool.size(); i++) {
			if (cool[i].first == (a[cool[i].second] > max(a[cool[i].second - 1], a[cool[i].second + 1]) ? 0 : max(a[cool[i].second - 1], a[cool[i].second + 1]) - a[cool[i].second] + 1)) {
				ans += cool[i].first;
				a[cool[i].second] += cool[i].first;
				need--;
			}
		}
	}  
	cout << ans << '\n';
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
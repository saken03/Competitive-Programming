/***
    AUTHOR:    shabylkhan
    CREATED:   13.08.2022 21:52:26

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < k; i++) {
		a[i].first = (int)1e9;
	}
	for (int i = 0; i < n; i++) {
		swap(a[i].first, a[i].second);
	}
	sort(a[i].begin(), a.end());
	for (int i = 0; i < n; i++) {
		
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
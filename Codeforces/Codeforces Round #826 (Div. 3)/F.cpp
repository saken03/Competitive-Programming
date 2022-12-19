/***
    AUTHOR:    shabylkhan
    CREATED:   11.10.2022 22:25:05

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.second >> a[i].first.first >> a[i].second;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		swap(a[i].first.first, a[i].first.second);
	}
	for (int i = 0; i < n; i++) {
		int r = i + 1; 
		while (r < n) {
			if (a[i].second != a[r].second) {
				
			}
		}
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
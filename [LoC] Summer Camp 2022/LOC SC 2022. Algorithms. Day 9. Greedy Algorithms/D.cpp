/***
    AUTHOR:    shabylkhan
    CREATED:   28.07.2022 15:49:53

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> td(n);
	for (int i = 0; i < n; i++) {
		cin >> td[i].second >> td[i].first;
	}
	sort(td.begin(), td.end());
	int ct = 0;
	for (int i = 0; i < n; i++) {
		int t = td[i].second;
		int d = td[i].first;
		if (ct + t <= d) {
			ct += t;
		}
		else {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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
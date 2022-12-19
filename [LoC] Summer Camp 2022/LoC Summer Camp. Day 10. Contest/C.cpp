/***
    AUTHOR:    shabylkhan
    CREATED:   29.07.2022 14:35:54

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> ox(m + 2, 0);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		ox[l]++;
		ox[r + 1]--;
	}
	for (int i = 1; i <= m; i++) {
		ox[i] += ox[i - 1];
	}
	vector<int> k;
	for (int i = 1; i <= m; i++) {
		if (ox[i] == 0) {
			k.push_back(i);
		}
	}
	cout << k.size() << '\n';
	for (int i : k) cout << i << ' ';
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
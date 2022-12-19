/***
    AUTHOR:    shabylkhan
    CREATED:   04.08.2022 21:01:27

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int m;
	cin >> m;
	vector<vector<int>> a(2, vector<int> (m));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
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
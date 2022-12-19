/***
    AUTHOR:    shabylkhan
    CREATED:   21.09.2022 15:13:42

***/

#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int z0[5005][5005], z1[5005][5005], c[5005];

void solve() {
	int n, x, y;
	cin >> n >> x >> y;

	if (x >= y) {
		vector<int> bug;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) bug.push_back(i);
		}

		long long score = 0;

		int bb = (int) bug.size();
		if (bb & 1) {
			cout << -1 << '\n';
			return;
		}
	
		if (x < y) {
			for (int i = 0; i < bb; i++) {
				if (i + 1 < bb && bug[i] + 1 == bug[i + 1]) score += x, used[i + 1] = 1;
			}
		}

		if (bb == 0) {
			cout << 0 << '\n';
			return;
		}

		if (bb == 2) {
			if (bug[0] + 1 != bug[1]) {
				cout << y;
			}
			else {
				cout << min(x, y + y);
			}
			cout << '\n';
		}

	else {
		cout << y * 1ll * bb / 2 << '\n';
	}
	return;
}

	for (int i = 0; i < 5005; i++) {
		for (int j = 0; j < 5005; j++) {
			z0[i][j] = z1[i][j] = INF;
		}
		c[i] = 0;
	}

	string a, b;
	cin >> a >> b; 
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) c[i + 1] = 1;
		else c[i + 1] = 0;
	}

	if (c[1] == 0) z0[1][0] = 0;
	else z1[1][1] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (c[i] == 0) {
				z0[i][j] = min(z0[i - 1][j], z1[i - 1][j]);
				if (j <= 1) z1[i][j] = min(z0[i - 1][j] + y, z1[i - 1][j] + x);
				else z1[i][j] = min(min(z0[i - 1][j] + y, z1[i - 1][j] + x), min(z0[i - 1][j - 2] + x, z1[i - 1][j - 2] + y));
			}
			else {
				if (j == 0) z0[i][j] = min(z0[i - 1][j + 1] + y, z1[i - 1][j + 1] + x);
				if (j < i) z0[i][j] = min(min(z0[i - 1][j + 1] + y, z1[i - 1][j + 1] + x), min(z0[i - 1][j - 1] + x, z1[i - 1][j - 1] + y));
				if (j == i) z0[i][j] = min(z0[i][j], min(z0[i - 1][j - 1] + x, z1[i - 1][j - 1] + y));
				
				if (j == 0) z1[i][j] = INF;
				else z1[i][j] = min(z0[i - 1][j - 1], z1[i - 1][j - 1]);
			}
		}
	}
	
	cout << z0[n][0] << '\n';
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
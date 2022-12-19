/***
    AUTHOR:    shabylkhan
    CREATED:   12.06.2022 12:44:24

***/

#include<bits/stdc++.h>

using namespace std;

char c[105][105], c2[105][105];

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			c[i][j] = x;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] != '.' && c[i][j] != '/' && c[i][j] != 92 && c[i][j] != ' ' && c[i][j] != '_') {
				c2[n - 2 - i][m - 1 - j] = c[i][j];
				c2[n - 2 - i - 1][m - 1 - j] = c[i - 1][j];
				c2[n - 2 - i][m - 1 - j - 1] = c[i][j - 1];
				c2[n - 2 - i][m - 1 - j + 1] = c[i][j + 1];
				c2[n - 2 - i + 1][m - 1 - j] = c[i + 1][j];
				c2[n - 2 - i + 1][m - 1 - j - 1] = c[i + 1][j - 1];
				c2[n - 2 - i + 1][m - 1 - j + 1] = c[i + 1][j + 1];
				c2[n - 2 - i + 2][m - 1 - j] = c[i + 2][j];
				c2[n - 2 - i][m - 1 - j - 2] = c[i][j - 2];
				c2[n - 2 - i][m - 1 - j + 2] = c[i][j + 2];
				c2[i][j] = c2[i][j + 1] = c2[i][j + 2] = c2[i][j - 1] = c2[i][j - 2] = c2[i - 1][j] = 
				c2[i + 1][j] = c2[i + 1][j - 1] = c2[i + 1][j + 1] = c2[i + 2][j] = '.';
			} 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c2[i][j];
		}
		cout << '\n';
	}
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
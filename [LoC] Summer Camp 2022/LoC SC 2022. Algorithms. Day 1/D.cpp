/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 14:51:40

***/

#include<bits/stdc++.h>

using namespace std;

char c[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;

bool good(int x, int y) {
	if (x >= n || x < 0 || y >= m || y < 0) return 0;
	return 1;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '#') {
				for (int d = 0; d < 4; d++) {
					if (good(i + dx[d], j + dy[d])) {
						if (c[i + dx[d]][j + dy[d]] == '.') c[i + dx[d]][j + dy[d]] = 'X';
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c[i][j];
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
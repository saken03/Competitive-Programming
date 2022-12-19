/***
    AUTHOR:    shabylkhan
    CREATED:   29.10.2022 17:15:35

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 123;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;            

void solve() {
 	cin >> n >> m;
 	vector<vector<char>> c(n, vector<char> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}

	set<pair<pair<int, int>, pair<int, int>>> s;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] != '.') continue;
			for (int dir = 0; dir < 4; dir++) {
				int x = i, y = j;
				int x1 = 1e8, y1 = 1e8, x2 = 0, y2 = 0;
				while (x + dx[dir] >= 0 && x + dx[dir] < n && y + dy[dir] >= 0 && y + dy[dir] < m && c[x + dx[dir]][y + dy[dir]] == '.') {
					x1 = min(x1, x);
					y1 = min(y1, y);
					x += dx[dir];
					y += dy[dir];
					x2 = max(x2, x);              
					y2 = max(y2, y);
				}
			}
			s.insert({{x1, y1}, {x2, y2}});
		}
	}

	vector<pair<pair<int, int>, pair<int, int>>> v;

	for (auto it = s.begin(); it != s.end(); it++) {                 
		auto x = *it;
		cout << x.first.first << ' ' << x.first.second << '-' << x.second.first << ' ' << x.second.second << '\n';
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
/***
    AUTHOR:    shabylkhan
    CREATED:   18.06.2022 20:46:24

***/

#include<bits/stdc++.h>

using namespace std;

int n, m;                       
vector<int> paths[50][50];

void solve() {
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	paths[0][0].push_back(a[0][0]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			if (i - 1 >= 0) for (int it : paths[i - 1][j]) {
				paths[i][j].push_back(it + a[i][j]);
			}
			if (j - 1 >= 0) for (int it : paths[i][j - 1]) {
				paths[i][j].push_back(it + a[i][j]);
			}
		}
	}
	
	for (int it : paths[n - 1][m - 1]) {
		if (it == 0) {
		//	cout << "YES\n";
			return;
		}
		 cout << it << ' ';
	}     
//	cout << "No\n";
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
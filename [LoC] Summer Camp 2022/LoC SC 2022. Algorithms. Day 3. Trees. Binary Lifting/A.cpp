/***
    AUTHOR:    shabylkhan
    CREATED:   20.07.2022 15:45:16

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> g[100500];
int parent[100500][25];

void dfs(int v) {
	for (int to : g[v]) {
		dfs(to);
		parent[to][0] = v;
	}
}

void solve() {                        
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	dfs(0);

	for (int k = 1; k <= 20; k++) {
		for (int i = 1; i <= n; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int k = 0; k <= 20; k++) {
			if (parent[i][k] != 0) {
				cout << parent[i][k] << ' ';
			}
			else break;
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
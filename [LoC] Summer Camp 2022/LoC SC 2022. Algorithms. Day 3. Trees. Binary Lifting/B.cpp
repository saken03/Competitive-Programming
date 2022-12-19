/***
    AUTHOR:    shabylkhan
    CREATED:   20.07.2022 15:45:16

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> g[100500];
int depth[100500];

void dfs(int v) {
	for (int to : g[v]) {
		depth[to] = depth[v] + 1;
		dfs(to);                 
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
	for (int i = 1; i <= n; i++) {
		cout << depth[i] - 1 << ' ';
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
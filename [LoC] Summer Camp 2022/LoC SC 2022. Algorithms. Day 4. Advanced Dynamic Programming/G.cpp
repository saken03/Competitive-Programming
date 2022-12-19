/***
    AUTHOR:    shabylkhan
    CREATED:   21.07.2022 16:21:23

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> g[100500];
int sub[100500], hei[100500], wei[100500];

void dfs(int v, int p) {
	for (int to : g[v]) {
		if (to == p) continue;
		dfs(to, v);
		sub[v] += sub[to];
		hei[v] = max(hei[v], hei[to] + 1);
		wei[v] += wei[to];
	}
	sub[v]++;   
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wei[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cout << wei[i] << ' ';
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
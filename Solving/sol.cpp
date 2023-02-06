#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
vector<int> g[MAXN], vis(MAXN), col(MAXN, -1);

void dfs(int v) {
	vis[v] = 1;

	for (int to : g[v]) {
		if (!vis[to]) {
			col[to] = col[v] ^ 1;
			dfs(to);
		}
	}
}

void check() {
	for (int i = 0; i < n; i++) {
		for (int to : g[i]) {
			if (col[i] == col[to]) {
				cout << "IMPOSSIBLE";
				exit(0);
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			col[i] = 0;
			dfs(i);
		}
	}

	check();

	for (int i = 0; i < n; i++) {
		cout << (col[i] == 0 ? 1 : 2) << ' ';
	}
}

int main() {                                                                         
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
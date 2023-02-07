#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

const int MAXN = 2e5 + 12;

int n, m;
vector<int> vis(MAXN), g[MAXN];
vector<bool> chosen(MAXN);

void clear() {
	for (int i = 0; i < MAXN; i++) 
		g[i].clear();
	fill(vis.begin(), vis.end(), false);
	fill(chosen.begin(), chosen.end(), false);	
}

void dfs(int v) {
	vis[v] = 1;

	for (const int to : g[v]) 
		if (!vis[to])
			dfs(to);
}

void solve() {
	cin >> n >> m;

	clear();

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	for (int i = 0; i < n; i++) {
		if (!vis[i]) 
			dfs(i);
	}
}

int main() {                                                                         
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tt = 1;
	cin >> tt;
	while (tt--) 
		solve();

	return 0;
}
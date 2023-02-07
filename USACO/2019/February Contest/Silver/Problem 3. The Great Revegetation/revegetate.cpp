/***
PROB: 
LANG: C++14
username: sakenseri1
***/
#include<bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int MAXN = 1e5 + 12;

int n, m;
vector<int> vis(MAXN), col(MAXN);
vector<pair<int, char>> g[MAXN];

void dfs(int v) {
	vis[v] = 1;

	for (const auto to : g[v]) 
		if (!vis[to.f]) {
			col[to.f] = col[v] ^ (to.s == 'D');
			dfs(to.f);
		}
}

void check() {
	for (int u = 0; u < n; u++) {
		for (const auto v : g[u]) {
			if ((col[u] == col[v.f] && v.s == 'D') 
			|| (col[u] != col[v.f] && v.s == 'S')) {
				cout << 0 << '\n';
				exit(0);
			}
		}
	}
}   

void solve() {        
	// we have only 2 possible answer: 0 or 2(in binary)
	// not perfectly sure about it
	// it's right for one component, but we may have several components

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		char opt;
		int a, b;
		cin >> opt >> a >> b;
		a--; b--;
		
		g[a].pb(mp(b, opt));
		g[b].pb(mp(a, opt));
	}

	// now let's check it's bipartitness
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			col[i] = 0;
			dfs(i);
			k++;
		}
	}

	check();
	
	cout << 1;
	for (int i = 0; i < k; i++) cout << 0;
	cout << '\n';
}

int main() {
	setIO("revegetate");

	solve();

	return 0;
}   

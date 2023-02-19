/***
PROB: 
LANG: C++14
username: sakenseri1
***/
#include<bits/stdc++.h>

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

const int MAXN = 2e5 + 10;

vector<int> g[MAXN], deepLevel(MAXN);
int farNode, maxLevel;

void dfs(int v, int p = -1) {
	for (const int to : g[v]) 
		if (to != p) {
			deepLevel[to] = deepLevel[v] + 1;
			if (deepLevel[to] >= maxLevel) {
				maxLevel = deepLevel[to];
				farNode = to;
			}
			dfs(to, v);
		}
}

void solve() {        
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(0);
	fill(deepLevel.begin(), deepLevel.end(), 0);
	dfs(farNode);
	cout << deepLevel[farNode] << '\n';
}

int main() {
	setIO("");

	solve();

	return 0;
}   

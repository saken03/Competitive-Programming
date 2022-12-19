#include<bits/stdc++.h>
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
#define pb push_back
 
using namespace std;

const int MAXN = 3e4 + 300;
 
vector<int> g[MAXN];
bool u[MAXN];

void dfs(int v) {
	u[v] = 1;
	for (int to : g[v]) {
		if (!u[to]) dfs(to);
	}
}

void solve() {
	int n, t;
	cin >> n >> t;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		g[i].pb(i + a);
	}
	for (int i = 1; i <= n; i++) u[i] = 0;
	dfs(1);
	cout << (u[t] ? "YES" : "NO") << '\n';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
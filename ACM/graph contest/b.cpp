#include<bits/stdc++.h>
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
#define pb push_back
 
using namespace std;
 
const int MAXN = 2e5 + 500;
 
int pr[MAXN], lvl[MAXN], mx[MAXN];
vector<int> g[MAXN];
 
void dfs(int v, int p = 0) {
	for (int to : g[v]) {
		if (to == p) continue;
		lvl[to] = lvl[v] + 1;
		pr[to] = v;
		dfs(to, v);
	}
	mx[v] = lvl[v];
	for (int to : g[v]) {
		if (to == p) continue;
		mx[v] = max(mx[v], mx[to]);
	}	
}
 
void solve() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b), g[b].push_back(a);
	}
	dfs(1);
	int d = 0, ans = 0;
	while (1) {
		if (lvl[x] == d + 1) break;
		if (lvl[x] > d + 2) x = pr[x];
		d++;
		ans += 2;
	}
	ans += 2 * (mx[x] - lvl[x] + 1);
	cout << ans << '\n';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
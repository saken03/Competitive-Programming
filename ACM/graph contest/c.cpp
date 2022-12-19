#include<bits/stdc++.h>
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
#define pb push_back
 
using namespace std;

const int MAXN = 1e5 + 500;
 
vector<int> g[MAXN];
bool u[MAXN];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	priority_queue<int> q;
	q.push(-1);
	u[1] = 1;
	while (!q.empty()) {
		int x = q.top();
		x = -x;
		cout << x << ' ';
		q.pop();
		for (int to : g[x]) {
			if (!u[to]) {
				q.push(-to);
				u[to] = 1;
			}
		}
	}
	cout << '\n';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
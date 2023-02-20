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

const int INF = (int)1e10;
const int MAXN = 1e5;

int n, m;
vector<int> g[MAXN], dist(MAXN),
	parent(MAXN);

void bfs(int s) {
  fill(dist.begin(), dist.end(), INF);
	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (const int to : g[v]) {
			if (dist[to] == INF) {
				q.push(to);
				parent[to] = v;
		  	dist[to] = dist[v] + 1;
			}
		}
	}
}

void solve() {        
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	bfs(0);

	if (dist[n - 1] == INF)
		cout << "IMPOSSIBLE\n";
	else {
		cout << dist[n - 1] + 1 << '\n';
		vector<int> v = {n - 1}; // one element n - 1
		while (v.back() != 0) 
			v.pb(parent[v.back()]);
		reverse(begin(v), end(v));
		for (const int i : v) cout << i + 1 << ' ';
	}

}

int main() {
	setIO("");

	solve();

	return 0;
}   

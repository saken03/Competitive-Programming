#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;
const int MAXN = 3e5 + 123;
const ll INF = 1e15;

vector<pair<int, ll>> g[MAXN];

void solve() {        
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}

	int s, t;
	cin >> s >> t;

	queue<int> q;
	vector<bool> was(n + 1, 0);
	vector<int> pr(n + 1, 0);
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		was[v] = 1;

		for (auto to : g[v]) {
			if (!was[to.f]) {
				q.push(to.f);
				if (d[to.f] > d[to.s])
			}
		}
	}
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	solve();
	return 0;
}
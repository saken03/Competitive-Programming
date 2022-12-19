/***
    AUTHOR:    shabylkhan
    CREATED:   25.07.2022 15:38:42

***/

#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()

using namespace std;

const int MAXN = 100500;
const int INF = 1e9;

vector<pair<int, int>> g[MAXN];
bool u[MAXN];
int d1[MAXN], d2[MAXN];

void solve() {
	int n, m, s, t;
	cin >> n >> m >> s >> t; s--;t--;
	for (int i = 0; i < n; i++) d1[i] = d2[i] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].pb(mp(b, c));
	}
	d1[s] = d2[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		u[x] = 1;
		q.pop();
		for (auto to : g[x]) {
			if (!u[to.f]) {
				if (d1[to.f] >= d1[x] + 1) {
					d1[to.f] = d1[x] + 1;
					d2[to.f] = d2[x] + to.s;
				}
				q.push(to.f);
			}
		}
	}
	if (d2[t] == INF) cout << "Unreachable\n";
	else cout << d2[t] << '\n';
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
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 123;
const long long INF = 1e13;

long long a[MAXN], b[15];
vector<long long> team;
vector<long long> g[MAXN];
int cnt;

void dfs(int v) {
	for (int to : g[v]) {
		team[to] = min(team[to], a[v]);
	}
} 

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int f = 15;
	while (f--) {
		team.push_back(INF);
	}

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		g[i].push_back(b[i]);
		team[b[i]] = min(team[b[i]], a[i]);
	}

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			for (int i = l; i <= r; i++) {
				a[i] += x;
				dfs(i); 
			}
		}
		else {
			int k;
			cin >> k;
			for (int i = 1; i <= n; i++) {
				if (team[b[i]] >= k) cnt++;
			}
			cout << cnt << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
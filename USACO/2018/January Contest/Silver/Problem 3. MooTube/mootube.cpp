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

const int N = 5005;

vector<pair<int, int>> g[N];
int cnt;

void dfs(int v, int p, int k) {
	for (const auto to : g[v]) {
		if (to.f == p) 
			continue;
		if (k <= to.s) {
		//	cout << "dbg: " << v << '\n';
			cnt++;
	  	dfs(to.f, v, k);	
		}	
	}
}

void solve() {        
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}

	while (q--) {
		int k, v;
		cin >> k >> v;
		v--;
		cnt = 0;
		dfs(v, -1, k);
		cout << cnt << '\n';
	}
}

int main() {
	setIO("mootube");

	solve();

	return 0;
}   

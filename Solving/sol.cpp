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
const int N = 1005;

int n, q, v[MAXN];
ll sum[MAXN];
vector<int> g[MAXN], g2[MAXN];

void dfs(int v, int p) {
  sum[v] += v[	v];
	for (const int to : v) 
		if (to != p) {
			dfs(to, p);
			dfs[v] += dfs[to];
		}
}

void upd
     
void solve() {        
	cin >> n >> q;
	                           	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(0, -1);

	for (int i = 0; i < q; i++) {
		int tp, s;
		cin >> tp >> s;
		s--;

		if (tp == 1) {
			int x;
			cin >> x;
			update(s, x);
		}
		else {    
			cout << sum[s] << '\n';
		}
	}
}

int main() {
	setIO("");
	solve();
	return 0;
}   

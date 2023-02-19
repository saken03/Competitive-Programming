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

const int MAXN = 1e5 + 10;

int n, m;
string type;
bool visited[MAXN];
vector<int> g[MAXN], farm(MAXN);
int compNumber;

void dfs(int v) {
	visited[v] = 1;
	farm[v] = compNumber;

	for (const int to : g[v]) 
		if (!visited[to] && type[v] == type[to]) 
			dfs(to);
}

void solve() {
	cin >> n >> m >> type;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	for (int i = 0; i < n; i++) 
		if (!visited[i]) {
			dfs(i);
			compNumber++;
		}

	while (m--) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (farm[a] != farm[b] || type[a] == c)
			cout << 1;
		else cout << 0;	
	}
}
                     
int main() {
	setIO("milkvisits");

	solve();

	return 0;
}   

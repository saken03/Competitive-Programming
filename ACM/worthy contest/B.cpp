#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 123;

int n, m, q;
long long w[MAXN];
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
long long team[MAXN];
int cnt;
bool already[MAXN], maks[MAXN];

vector<int> g[MAXN];

void dfs(int v, int val) {
	bool aks = 1;
	for (int to : g[v]) {
		team[to] += val;
		if (!already[to] && team[to] >= d[to]) {
			already[to] = 1;
			cnt++;          
		}
	}                    
}

void solve() {
	cin >> n >> m >> q;
	
	for (int i = 1; i <= n; i++) {
		cin >> w[i];           
	}

	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		
		team[i] = w[a[i]] + w[b[i]] + w[c[i]];
		if (team[i] >= d[i]) {
			cnt++;
			already[i] = 1;
		}

		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
		g[c[i]].push_back(i);
	}
	
	cout << cnt << '\n';
	for (int i = 1; i <= q; i++) {
		int p, v;
		cin >> p >> v;
		dfs(p, v);
		cout << cnt << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);   
	cin.tie(0);
	
	solve();

	return 0;
} 
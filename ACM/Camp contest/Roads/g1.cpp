#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 123;

vector<pair<int, int>> g[MAXN];

void solve() {
	int n;
	cin >> n;
	
	for (int i = 1; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		g[a[i]].pb(mp(b[i], c[i]));
		g[b[i]].pb(mp(a[i], c[i]));
	}

	for (int i = 1; i < n; i++) {
		int r1 = 0, r2 = 0;
		queue<pair<int, int>> q;
		vector<bool> u(n + 1);
		q.push(a[i]);
		u[b[i]] = 1;	

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int to : g[v]) {
				if (!u[to.f]) {
					
				}
			}
		}

		if (r1 > r2) swap(r1, r2);
		cout << r1 << ' ' << r2 << '\n';
	}                                                  
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
} 
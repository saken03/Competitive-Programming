/***
    AUTHOR:    shabylkhan
    CREATED:   29.09.2022 21:35:31

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> g[MAXN];
int lvl[MAXN];

void dfs(int v) {
	for (int to : g[v]) {
		lvl[to] = lvl[v] + 1;
		dfs(to);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		g[p].push_back(i);
	}

	dfs(1);

	multiset<int> S;
	for (int i = 2; i <= n; i++) {
		S.insert(lvl[i]);
	}

	vector<int> R(200500, 0);

	while (k > 0) {
		int el = *(S.rbegin() - R);

		int K = el - (el + 1) / 2;
		while (K > 0) {
			int ll = *(S.rbegin());
			S.insert((ll + 1) / 2);
			R++;
			K--;
		}
		k--;
	}

	cout << *S.rbegin() << '\n';
}
                        
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 
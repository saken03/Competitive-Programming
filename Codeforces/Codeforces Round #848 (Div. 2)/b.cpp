#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> p(n);
	unordered_map<int, int> pos;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	vector<
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) 
		solve();
	return 0;
}
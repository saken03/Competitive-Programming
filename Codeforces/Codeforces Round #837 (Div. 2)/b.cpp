#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.s < b.s) return 1;
	else if (a.s == b.s) {
		if (a.f <= b.f) return 1;
		return 0;
	}
	return 0;
}

void solve() {               
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].f >> a[i].s;
	}
	sort(a.begin(), a.end());
	ll ans = (n * n + n) >> 1ll;
	int la = 1;
	for (int i = 0; i < m; i++) {
		ans -= (n - a[i].s + 1) * 1ll * (a[i].f - la + 1);
		la = a[i].f + 1;
	}
	cout << ans << '\n';
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

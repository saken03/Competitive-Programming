#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 123;
const int INF = 1e9;

int n, a[MAXN], e[MAXN], pref[MAXN], suff[MAXN];

int dist(int a, int b) {
	return abs(a - b);
}

void solve() {
	cin >> n;
	pref[0] = INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		e[i] = INF;
		if (a[i] == 0) pref[i] = i;
		else pref[i] = pref[i - 1];
	}
	suff[n + 1] = INF;
	for (int i = n; i >= 1; i--) {
		if (a[i] == 0) suff[i] = i;
		else suff[i] = suff[i + 1];
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (dist(i, pref[i]) <= dist(i, suff[i])) {
			ans.pb(pref[i]);
			e[i] = pref[i];
		}
		else {
			ans.pb(suff[i]);
			e[i] = suff[i];
		}
	}
	
	int k = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (e[i] == e[j] && dist(e[i], i) == dist(e[j], j)) k++;
		}
	}
	cout << k << '\n';
	for (int i : ans) cout << i << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
} 
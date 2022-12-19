#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;

bool test(vector<int> a, int x) {
	int n = sz(a);
	for (int i = 0; i < n; i++) {
		a[i] = abs(x - a[i]);
	}
	bool inc = 1;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			inc = 0;
			break;
		}
	}
	if (inc) return 1;
	return 0;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int mn = (int)1e9, mx = 0;
	for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);
/*	                                 
	for (int l = 1; l < n; l++) {
		for (int i = 1; i < n; i++) {
			a[i - 1] = abs(a[i - 1] - a[i]);  
		}
	}
 	cout << a[0];

	return;
*/
	bool dec = 1, inc = 1, eq = 1;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i]) {
			dec = 0;
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			inc = 0;
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i - 1] != a[i]) {
			eq = 0;
			break;
		}
	}
	
	if (inc) {
		cout << 0 << '\n';
		return;
	}

	if (eq || dec) {
		cout << (int)1e9 << '\n';
		return;
	}
	  ll mean = (mn + mx + 1) / 2;
		if (test(a, mean)) {
			cout << mean << '\n';
			return;
		}

	cout << -1 << '\n';
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

/***
    AUTHOR:    shabylkhan
    CREATED:   31.10.2022 19:30:40

***/

#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 123;

int n, a[MAXN], f[MAXN];
vector<int> v[MAXN];

void upd(int pos, int val) {
	while (pos <= MAXN) {
		f[pos] += val;
		pos += pos & -pos;
	}
}

int get(int pos) {
	int sum = 0;
	while (pos > 0) {
		sum += f[pos];
		pos -= pos & -pos;
	}
	return sum;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		if (a[i] < MAXN)
			v[a[i]].pb(i);
		upd(i, 1);
	}

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int to = min(MAXN, a[i]); // check for sure..
		res += get(to);
		for (int x : v[i]) {
			upd(x, -1);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i <= a[i]) res--;
	}
	cout << (res / 2) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	} 

	return 0;
} 

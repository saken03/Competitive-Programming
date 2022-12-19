/***
    AUTHOR:    shabylkhan
    CREATED:   02.11.2022 18:25:21

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXA = 1e5 + 123;
const long long INF = 1e12;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), d(MAXA);
	map<int, int> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}

	for (int i = 1; i <= MAXA; i++) {
		d[i] += m[i] - 1;
		for (int j = i + i; j <= MAXA; j += i) {
			d[j] += m[i];
		}

	}
/*
	int x;
	cin >> x;
	cout << d[x];
	return;
*/
	vector<long long> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] += pref[i - 1] + d[a[i]];
	}

	long long mn = INF;
	for (int i = k; i <= n; i++) {
		mn = min(mn, pref[i] - pref[i - k]);
	}
	cout << mn << '\n';
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
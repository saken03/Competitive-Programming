/***
    AUTHOR:    shabylkhan
    CREATED:   22.07.2022 14:36:49

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int t, r;
	cin >> t >> r;
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<long long> pb(n + 1);
	vector<long long> ph(n + 1);
	ph[0] = 0;      	
	pb[0] = 1;
	for (int i = 0; i < n; i++) {
		ph[i + 1] = ((ph[i] * t) % r + int(s[i])) % r;
		pb[i + 1] = (pb[i] * t) % r;
	}

	int m;
	cin >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		int res = (ph[b + 1] - (ph[a] * pb[b + 1 - a]) % r) % r;
		if (res < 0) res+=r;
		cout << res << '\n'; 
	}

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
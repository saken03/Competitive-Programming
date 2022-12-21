/***
PROB: 
LANG: C++14
username: sakenseri1
***/
/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

***/
#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const ll MOD = 1e9 + 7;

void solve() {        
	
	int n;
	cin >> n;

	vector<int> over(2 * n + 1), l(n), r(n), pw(n);
	pw[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		over[l[i]]++;
		over[r[i]]--;
	}
	for (int i = 1; i < n; i++) pw[i] = pw[i - 1] * 2 % MOD;

	for (int i = 1; i <= 2 * n + 1; i++) over[i] += over[i - 1];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += pw[n - 1 - over[l[i] - 1]];
		ans %= MOD;
	}
	cout << ans << '\n';
}

int main() {
	setIO("help");

	solve();

	return 0;
}   

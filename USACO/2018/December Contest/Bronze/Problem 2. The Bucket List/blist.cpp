/***
PROB: 
LANG: C++14
username: sakenseri1
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

void solve() {
	int n;
	cin >> n;
	vector<int> pref(1005);
	for (int i = 0; i < n; i++) {
		int s, t, b;
		cin >> s >> t >> b;
		for (int j = s; j <= t; j++) 
			pref[j] += b;
	}
	
	int ans = 0;
	for (int i = 1; i <= 1000; i++) 
		ans = max(ans, pref[i]);
	cout << ans << '\n';	
}

int main() {
	setIO("blist");

	solve();

	return 0;
}   

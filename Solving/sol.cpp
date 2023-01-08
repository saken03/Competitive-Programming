#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

typedef long long ll;

const ll MOD = (ll) 1e9 + 7;

void solve() {	
	int n, p, k;
	cin >> n >> p >> k;
	
	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());

	vector<vector<int>> s(n, vector<int> (p));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cin >> s[i][j];
		}
	}

	vector<vector<ll>> dp(n, vector<ll> (1 << p));
	for (int m = 0; m < (1 << p); m++) {
		
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
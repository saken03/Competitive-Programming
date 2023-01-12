/***
PROB: skidesign
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

int n, a[1005];

int square(int x) {
	return x * x;
}

int range(int l, int r) {
	if (l > r) return (int)1e10;

	int cost = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < l) {
			cost += square(a[i] - l);
		}
		if (a[i] > r) {
			cost += square(r - a[i]);
		}
	}  
	return cost;
}

void solve() {        
  cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ans = (int)1e10;
	int need = (a[n - 1] - a[0]) - 17;
	if (need <= 0) 
		cout << 0 << '\n';
	else {
		for (int i = 0; i <= need; i++) {
			int j = need - i;
			ans = min(ans, range(a[0] + i, a[n - 1] - j));
		}
		cout << ans << '\n';
	}
}

int main() {
	setIO("skidesign");

	solve();

	return 0;
}   

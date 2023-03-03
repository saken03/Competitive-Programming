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
	if (n & 1) cout << -1 << '\n';
	else cout << 1 << ' ' << n / 2 << '\n';
/*
	for (int x = 1; x <= n; x++) 
		for (int y = x; y <= n; y++) {
			ll a = 1, b = 1;
			for (int i = 0; i < y; i++) 
				a *= x;
			a *= y;
			for (int i = 0; i < x; i++)
				b *= y;
			b *= x;

			if (a + b == n) {
				cout << x << ' ' << y << '\n';
				return;
			}
		}
	cout << -1 << '\n';	
*/
}

int main() {
	setIO("");
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
	return 0;
}
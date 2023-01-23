#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MOD = (int)1e9 + 7;

ll sum(ll n) {
	return (n * n + n) / 2ll;
}

void solve() {
	int n;
	cin >> n;
	ll f = 1;
	for (int i = 1; i <= n; i++) {
		f *= i;
		f %= MOD;
	}
	f *= n;
	f %= MOD;
	f *= n - 1;
	f %= MOD;
	cout << f << '\n';
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

#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 123;

ll fact[MAXN];

ll binpow(int a, int n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return res;
}

void pre() {
	fact[0] = fact[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
}

void solve() {
	string s;
	cin >> s;
	vector<int> m(27);
	for (char c : s) m[c - 'a']++;
	int ans = fact[sz(s)];
	for (int i = 0; i < 27; i++) {
		ans *= binpow(fact[m[i]], MOD - 2);
		if (binpow(fact[m[i]], MOD - 2) == 0) {
			cout << i << ' ';
			return;
		} 
		ans %= MOD;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	pre();
	solve();

	return 0;
} 

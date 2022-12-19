#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first                                 
#define s second
                
typedef long long ll;

using namespace std;

const ll INF = 1e18;
const int MOD = 998244353;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int a = 0, b = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			a++;
			if (a >= (i + 1)) {    
				ans += 1 << i;
				ans %= MOD;
			}
			else {
				int left = i + 1 - a;
				ans += 1 << left;
				ans %= MOD;
			}
		}
		else {
			b++;
			if (b >= (i + 1)) {
				ans += 1 << i;
				ans %= MOD;
			}
			else {
				int left = i + 1 - b;
				ans += 1 << left;
				ans %= MOD;
			}
		}
	}
	cout << ans << '\n';
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

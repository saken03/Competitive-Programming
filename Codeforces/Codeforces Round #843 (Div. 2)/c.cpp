#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

bool bit(ll a, int b) {
	return (a & (1ll << b));
}

void solve() {
	ll n, x;
	cin >> n >> x;
	int lg = 0;
	ll t = n;
	while (t) {
		t >>= 1;
		lg++;
	}

	ll b = 0;
	int l = 0;
	for (int i = 0; i <= lg; i++) {
		if (bit(n, i) && bit(x, i)) {
			b += (1ll << i);
		}
		else if (bit(n, i) && !bit(x, i)) {
			l = i;
		}
		else if (!bit(n, i) && bit(x, i)) {
			cout << -1 << '\n';
			return;
		}	
	}

	for (int i = l; i < lg; i++) {
		if (!bit(n, i)) {
			b += (1ll << i);
			break;
		}
	}

	cout << b << '\n';
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

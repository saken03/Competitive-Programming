#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n;
	cin >> n;
	map<ll, int> m;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		ll x = a[i];
		for (int j = 2; j * 1ll * j <= x; j++) {
			if (x % j == 0) {
				m[j]++;
				if (m[j] > 1) {
					cout << "YES\n";
					return;
				}
				if (x / j != j) {
					m[x / j]++;
					if (m[x / j] > 1) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
		m[x]++;
		if (m[x] > 1) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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

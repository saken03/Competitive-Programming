#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<int, ll>> p;
	set<ll> s;
	for (ll p = 1; p <= INF; p += p) {
		s.insert(p);
	}
	for (int i = 0; i < n; i++) {
		auto it = s.lower_bound(a[i]);
		while (a[i] < *it) {
			if (a[i] + a[i] < *it) p.pb(mp(i + 1, a[i])), a[i] += a[i];
			else {
				p.pb(mp(i + 1, *it - a[i]));
				break;
		 	}
		}
	}
	cout << sz(p) << '\n';
	for (auto i : p) cout << i.f << ' ' << i.s << '\n';
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

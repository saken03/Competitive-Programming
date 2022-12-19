#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].f;
		a[i].s = i;
	}
	vector<ll> pref(n);
	pref[0] = a[0].f;
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i].f;
	}
	sort(a.begin(), a.end());

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

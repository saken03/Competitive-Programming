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
	vector<int> a(n - 1);
	ll x; cin >> x;
	for (int i = 0; i < n - 1; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (x < a[i]) {
			x += (a[i] - x + 1) >> 1;
		}
	}
	cout << x << '\n';
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

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
	vector<int> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll g = 1, pref = 0;
	for (int i = 0; i < n - 1; i++) {
		sum -= a[i];
		pref += a[i];
		g = max(g, __gcd(sum, pref));
	}
	cout << g << '\n';
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

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
	map<int, bool> m;
	int mn = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!i) mn = a[i];
		if (i) mn = min(mn, __gcd(mn, a[i]));
	}
	cout << a[n - 1] / mn << '\n';
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
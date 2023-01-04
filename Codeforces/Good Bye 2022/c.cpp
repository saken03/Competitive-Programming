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
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			cout << "NO\n";
			return;
		}
	}
             
	for (int mod = 2; mod <= n; mod++) {
		vector<int> cnt(mod);
		for (int i = 0; i < n; i++) {
			cnt[a[i] % mod]++;
		}
		if (*min_element(cnt.begin(), cnt.end()) >= 2) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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

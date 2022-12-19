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
	vector<int> a(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a.begin(), a.end());
	ll ans = a[n - 1] - a[0], cnt = 0;
	if (ans == 0) {
		cout << n * 1ll * (n - 1) << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		cnt += m[a[i] - ans] + m[a[i] + ans];
	}
	cout << cnt << '\n';
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

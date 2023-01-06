#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0, cur = 1;
	for (int i = 0; i < n; i++) {
		if (cur == a[i]) {
			cur++;
		}
		else {
			cnt++;
		}
	}
	int ans = cnt / k;
	if (cnt % k != 0) ans++;
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

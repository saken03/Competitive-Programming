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
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 2 == 0) {
		cout << 0 << '\n';
		return;
	}
	int ans = (int)1e5;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		if (a[i] % 2 == 0) {
			while (a[i] % 2 == 0) {
				cnt++;
				a[i] >>= 1;
			}
		}
		else {
			while (a[i] % 2) {
				cnt++;
				a[i] >>= 1;
			}
		}
		ans = min(ans, cnt);
	}
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

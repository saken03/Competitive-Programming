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
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cur1 = 0, cur2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			cur1 = 0;
			cur2++;
			if (cur2 == 2) {
				ans++;
				cur2--;
			}
		}
		else {
			cur2 = 0;
			cur1++;
			if (cur1 == 2) {
				ans++;
				cur1--;
			}
		}
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

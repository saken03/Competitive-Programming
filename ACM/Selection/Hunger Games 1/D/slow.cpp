/***
    AUTHOR:    shabylkhan
    CREATED:   01.10.2022 20:34:13

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 500;

int n, m;

pair<int, int> a[MAXN];
vector<int> d(m);

bool Could(int x) {
	int j = 0, par = 0;
	for (int i = x; i >= 0 && j < m; i--, j++) {
		if (a[i].first <= d[j]) {
			par++;           
		}  
	}
	return par;
}

void solve() {
	cin >> n >> m;
                                                
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;
	for (int i = 0; i < m; i++) cin >> d[i];

	sort(a, a + n);
	sort(d.rbegin(), d.rend());

	int l = 0, r = n - 1, ans = 0;
	while (l <= r) {                                    
		int mid = (l + r) >> 1;
		if (Could(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
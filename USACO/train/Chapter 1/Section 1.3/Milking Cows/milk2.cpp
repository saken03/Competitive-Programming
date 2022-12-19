/*
	PROB: milk2
	LANG: C++14
	USERNAME: sakense1
*/


/***
    AUTHOR:    shabylkhan
    CREATED:   28.09.2022 14:06:00

***/

#include<bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[5005];

void solve() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + n);

	vector<pair<int, int>> cm;	
	int L = 0, R = 0;

	for (int i = 0; i < n; i++) {
		int l = a[i].first, r = a[i].second;

		if (L == 0 && R == 0) {
			L = l;
			R = r;
		}
		else {
			if (R >= l) {
				R = max(R, r);
				//L = min(L, l);
			}
			else {
				cm.emplace_back(L, R);
				L = l;
				R = r;
			}
		}
	}
	cm.emplace_back(L, R);
/*			
	for (pair<int, int> i : cm) {
		cout << i.first << ' ' << i.second << '\n';
	}
*/
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < (int) cm.size(); i++) {
		ans1 = max(ans1, cm[i].second - cm[i].first);
		if (i > 0) ans2 = max(ans2, cm[i].first - cm[i - 1].second);
	}
	cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
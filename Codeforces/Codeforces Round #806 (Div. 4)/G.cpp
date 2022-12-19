/***
    AUTHOR:    shabylkhan
    CREATED:   12.07.2022 22:23:27

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<vector<int>> pref(n + 1, 31);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	    	
//	pref[n - 1] = a[n - 1] >> 1;
	for(int i = 0; i < 31; i++) {
		pref[n - 1][i] = a[n - 1] >> i; 
 	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < 31; j++) {
			pref[i][j] += (a[i] >> j) + pref[i + 1];
		}
	}

	int cost = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i] - k;
		
		cost = max(cost, cur + pref[i + 1]);
	}
	cout << cost << '\n';
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
/***
    AUTHOR:    shabylkhan
    CREATED:   13.10.2022 21:49:20

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;  
	
	vector<int> a(n), ops(n);
	int mx = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < 34; j++) {
			if (bit(a[i], j)) {
				bts[j].push_back(a[i]);
			}
		}
		mx = max(mx, a[i]);
		ops[i] = a[i];
		if (i) ops[i] |= ops[i - 1];
	}
	                           
	cout << mx << ' ';
	
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
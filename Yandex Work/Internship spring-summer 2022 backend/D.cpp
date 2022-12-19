/***
    AUTHOR:    shabylkhan
    CREATED:   12.06.2022 13:51:22

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	vector<int> l(n), c0(n, 0), c1(n, 0), last0, last1;
	
	for (int i = 0; i < n; i++) {
		c0[i] = (i > 0 ? c0[i - 1] : 0) + (s[i] == '0');
		c1[i] = (i > 0 ? c1[i - 1] : 0) + (s[i] == '1');
		
		if (s[i] == '1') {
			bool found = 0;
			for (int j : last1) {
				if (c1[i] - (j - 1 >= 0 ? c1[j - 1] : 0) > c0[i] - (j - 1 >= 0 ? c0[j - 1] : 0)) {
					found = 1;
					l[i] = j;
					break;
				}
			}
			if (!found) l[i] = -1;
			last1.push_back(i); 
		}
		else {
			bool found = 0;
			for (int j : last0) {
				if (c0[i] - (j - 1 >= 0 ? c0[j - 1] : 0) > c1[i] - (j - 1 >= 0 ? c1[j - 1] : 0)) {
					found = 1;
					l[i] = j;
					break;
				}
			}
			if (!found) l[i] = -1; 
			last0.push_back(i);
		}
	}

	for (int ll : l) {
		cout << (ll == -1 ? -1 : ll + 1) << ' ';
	}
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
/***
    AUTHOR:    shabylkhan
    CREATED:   05.06.2022 21:52:02

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int k, n;
	cin >> k >> n;
	vector<vector<bool>> better(k, vector<bool>(n));
	for (int s = 0; s < k; s++) {
		vector<int> session(n);
		for (int& c : session) {
			cin >> c;
			c--;
		}
		for (int i = 0; i < (int)session.size(); i++) {
			for (int j = i + 1; j < (int)session.size(); j++) {
				better[session[j]][session[i]] = 1;
			}
		}
	}	
	 
	int better_pairs = 0;
	for (int c1 = 0; c1 < n; c1++) {
		for (int c2 = c1 + 1; c2 < n; c2++) {
			better_pairs += !better[c1][c2] || !better[c2][c1];
		}
	}
	cout << better_pairs;
}

int main() {
//	freopen("gymnastics.in", "r", stdin);
//	freopen("gymnastics.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
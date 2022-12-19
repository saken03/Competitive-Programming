/***
PROB: beads
LANG: C++14
username: sakenseri1
***/

/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

***/
#include<bits/stdc++.h>

using namespace std;

int n, ans;
string s;
int lft[800][2];
int rgt[800][2];

void solve() {
	cin >> n >> s;

	s = " " + s + s + " ";
	
	lft[0][0] = lft[0][1] = 0;
	for (int i = 1; i <= n + n; i++) {
		if (s[i] == 'r') lft[i][0] = lft[i - 1][0] + 1, lft[i][1] = 0;
		else if (s[i] == 'b') lft[i][1] = lft[i - 1][1] + 1, lft[i][0] = 0;
		else if (s[i] == 'w') {
			lft[i][0] = lft[i - 1][0] + 1;
			lft[i][1] = lft[i - 1][1]	+ 1;
		}
	}
	rgt[n + n + 1][0] = rgt[n + n + 1][1] = 0;
	for (int i = n + n; i >= 1; i--) {
		if (s[i] == 'r') rgt[i][0] = rgt[i + 1][0] + 1, rgt[i][1]	= 0;
		else if (s[i] == 'b') rgt[i][1] = rgt[i + 1][1] + 1, rgt[i][0] = 0;
		else if (s[i] == 'w') rgt[i][0] = rgt[i + 1][0] + 1, rgt[i][1] = rgt[i + 1][1] + 1;		
	}

	int ans = 0;
	for (int i = 1; i <= n + n; i++) {
		ans = max(ans, max(lft[i][0], lft[i][1]) + max(rgt[i + 1][0], rgt[i + 1][1])); 
	}
	ans = min(ans, n);

	cout << ans << '\n';
}                                                 

int main() {
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
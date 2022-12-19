/***
    AUTHOR:    shabylkhan
    CREATED:   28.10.2022 18:18:27

***/

#include<bits/stdc++.h>

using namespace std;

bool a[1005][1005], ch[1005][1005];

void solve() {
	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)s[i].size(); j++) {
			if (s[i][j] == '*') a[i + 1][j + 1] = 1;
			else a[i + 1][j + 1] = 0;
			ch[i + 1][j + 1] = 0;
		}
	}


	for (int i = 0; i <= n + 1; i++) {
		a[i][0] = a[i][n + 1] = 1;
	}
	for (int j = 0; j <= n + 1; j++) {
		a[0][j] = a[n + 1][j] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == a[i - 1][j - 1] && a[i - 1][j - 1] == a[i - 1][j + 1] && a[i - 1][j + 1] == a[i + 1][j - 1] && a[i - 1][j + 1] == a[i + 1][j + 1] && a[i + 1][j + 1] == 1) {
				cout << "krestik: " << i << ' ' << j << '\n';
				ch[i][j] = ch[i - 1][j - 1] = ch[i - 1][j + 1] = ch[i + 1][j - 1] = ch[i + 1][j + 1] = 1;
			}
			if (a[i - 1][j] == a[i][j - 1] && a[i][j - 1] == a[i][j + 1] && a[i][j + 1] == a[i + 1][j] && a[i + 1][j] == 1) {
				cout << "nolik: " << i << ' ' << j << '\n';	
				ch[i - 1][j] = ch[i][j - 1] = ch[i][j + 1] = ch[i + 1][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] && !ch[i][j]) {
		  	cout << "NO\n";
		  	return;
			}  
		}
	}
	cout << "YES\n";  
/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << ch[i][j];
		}
		cout << '\n';
	}
*/	              
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
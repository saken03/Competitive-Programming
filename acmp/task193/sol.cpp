/***
    AUTHOR:    shabylkhan
    CREATED:   12.10.2022 21:27:26

***/

#include<bits/stdc++.h>

using namespace std;

int a[205][205];
pair<> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i - 1][j] == a[i][j - 1]) {
				ans[a[i][j - 1]]
			}
		}
	}

	return 0;
} 
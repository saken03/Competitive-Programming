/***
    AUTHOR:    shabylkhan
    CREATED:   10.06.2022 22:39:58

***/

#include<bits/stdc++.h>

using namespace std;

int n, m, K;
string a, b;

string rec(int i, int j, int k, int last, string cur) {
	if (i == n - 1 || j == m - 1) {
		return cur;
	}

	if (k == K) {
		if (last == 0) rec(i, j + 1, 1, 1, cur + b[j]);
		else rec(i + 1, j, 1, 0, cur + a[i]); 
	}                           

	if (last == -1) {
		if (a[i] < b[j]) {
			rec(i + 1, j, k + 1, 0, cur + a[i]);
		}
		else {
			rec(i, j + 1, k + 1, 1, cur + b[j]);
		}
	}
	else if (last == 0) {
		if (a[i] < b[j]) {
			rec(i + 1, j, k + 1, 0, cur + a[i]);
		}
		else {
			rec(i, j + 1, 1, 1, cur + b[j]);
		}
	}
	else {
		if (a[i] < b[j]) {
			rec(i + 1, j, 1, 0, cur + a[i]);
		}
		else {
			rec(i, j + 1, k + 1, 1, cur + b[j]);
		}
	}

}

void solve() {
	cin >> n >> m >> K;

	cin >> a >> b;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	cout << rec(1, 0, 1, 0, "" + a[0]) << '\n';
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
/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 15:02:53

***/

#include<bits/stdc++.h>

using namespace std;

int a[105], pref[105];
string ans;

string cons(int[] a, int i) {
	string t = "";
	for (int i = 0; i <= i; i++) {
		t += "L";
	}
	for 
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (i == 0) pref[i] = a[i];
		else pref[i] = a[i] + pref[i - 1];
	}
	int mx = 121221;
	string s = "";
	for (int i = 0; i < n - 1; i++) {
		if (abs(pref[i + 1] - pref[i]) < mx) {
			mx = pref[i + 1] - pref[i];
			s = cons(a, i);
	 	}
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
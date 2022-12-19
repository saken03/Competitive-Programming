/***
    AUTHOR:    shabylkhan
    CREATED:   13.10.2022 21:18:07

***/

#include<bits/stdc++.h>

using namespace std;

void add(map<int, int>& a, int k, string b) {
	for (char i : b) {
		a[i - 'a'] += k;
	}
}
                                           
string query(map<int, int> a, map<int, int> b) {
	int i = 0, j = 25;
	 while (1) {
		while (!a[i]) {
			i++;
			if (i == 26) break;	
		}
		while (!b[j]) {
			j--;
			if (j == -1) break;
		}
		if (i < j) {
			return "YES";
		}
		else if (i == j) {
			if (a[i] < b[j]) {
				a[i] = 0;
				if (qa.empty()) return "YES";
				else return "NO";
			}
			else return "NO";
		}
	 }
}

void solve() {
	int q;
	cin >> q;

	// counters for s and t
	map<int, int> s, t;
	s[0] = 1;
	t[0] = 1;

	while (q--) {                                
		int d, k;
		string x;
		cin >> d >> k >> x;
		if (d == 1) {
			add(s, k, x);
		}
		else {
			add(t, k, x);
		}
		cout << query(s, t) << '\n';
	}
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
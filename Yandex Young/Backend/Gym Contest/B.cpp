/***
    AUTHOR:    shabylkhan
    CREATED:   07.06.2022 11:19:46

***/

#include<bits/stdc++.h>

using namespace std;

bool free(string s) {
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] != '.') return 0;
	}
	return 1;
}

void print(vector<string> a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
} 

bool found = 0;

void take(vector<string> &a, int k, int x, int len) {
	cout << "Passengers can take seats: ";
	string seats = "";
	
	for (int i = x; i < x + len; i++) {
		a[k][i] = 'X';
		seats += k + 1 + '0';
		if (i > (int)a[k].size() / 2) seats += i - 1 + 'A';
		else seats += i + 'A';
		if (i + 1 != x + len) seats += ' ';
	}
	cout << seats << '\n';
	print(a, (int)a.size());

	for (int i = x; i < x + len; i++) {
		a[k][i] = '#';
	}
	found = 1;
}

void solve() {
	int n;
	cin >> n;

	string cannot = "Cannot fulfill passengers requirements";

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m;
	cin >> m;
	while (m--) {
		int num;
		string side, position;
		cin >> num >> side >> position;

		found = 0;
		for (int i = 0; i < n; i++) {
			if (side == "left") {
				if (position == "window") {
					if (free(a[i].substr(0, num))) {
						take(a, i, 0, num);
						break;
					}           
				}
				else {
					if (free(a[i].substr(3 - num, num))) {
						take(a, i, 3 - num, num);
						break;
					}
				}
			}
			else {
				if (position == "window") {
					if (free(a[i].substr(7 - num, num))) {
						take(a, i, 7 - num, num);
						break;
					}
				}
				else {
					if (free(a[i].substr(4, num))) {
						take(a, i, 4, num);
						break;
					}
				} 	
			}
		}

		if (!found) {
			cout << cannot << '\n';
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

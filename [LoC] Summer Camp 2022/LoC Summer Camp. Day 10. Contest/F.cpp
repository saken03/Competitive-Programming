/***
    AUTHOR:    shabylkhan
    CREATED:   29.07.2022 14:45:54

***/

#include<bits/stdc++.h>

using namespace std;

int to_num(string s) {
	int n = 0;
	for (char c : s) {
		n *= 10;
		n += c - '0';
	}
	return n;
}

void solve() {
	int n;
	cin >> n;
	int cur = 1;
	bool fishy = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (s != "mumble") {
			int t = to_num(s);
			if (cur == -1) {
				cur = t;     
			}
			if (cur != t) {
				fishy = 1;
			}              
		}
		if (cur != -1) cur++;
	}
	cout << (fishy ? "something is fishy" : "makes sense");
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
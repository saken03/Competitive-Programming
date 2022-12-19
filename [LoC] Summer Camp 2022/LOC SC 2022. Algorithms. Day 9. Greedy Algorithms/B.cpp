/***
    AUTHOR:    shabylkhan
    CREATED:   28.07.2022 15:12:16

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long b;
	cin >> b;

	vector<long long> note(n);
	for (int i = n - 1; i >= 0; i--) {
		long long cur = b / a[i];
		b -= cur * a[i];
		note[i] = cur;         
		}
	
	if (b != 0) cout << "Impossible";
	else for (int i = 0; i < n; i++) {
		cout << note[i] << ' ';
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
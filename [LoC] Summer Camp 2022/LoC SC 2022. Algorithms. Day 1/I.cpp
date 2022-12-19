/***
    AUTHOR:    shabylkhan
    CREATED:   06.09.2022 12:45:57

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	set<int> s;

	for (int i = 1; i <= 100000; i++) {
		s.insert(i);
	}

	map<int, int> park;

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		int x;
		cin >> x;
		if (c == '+') {
			cout << *s.begin() << '\n';
		  park[x] = *s.begin();
			s.erase(s.begin());
		}
		else {
			s.insert(park[x]);
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
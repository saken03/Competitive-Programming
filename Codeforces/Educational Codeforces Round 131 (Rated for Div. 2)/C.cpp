/***
    AUTHOR:    shabylkhan
    CREATED:   08.07.2022 20:56:53

***/

#include<bits/stdc++.h>

using namespace std;

set<int> s[200500];

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), chrono(m + 12, 0);
	vector<pair<int, int>> done(n, pair<int, int> {0, 0});

	for (int i = 1; i <= n; i++) {
		s[i].clear();
	}
	
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		s[a[i]].insert(i + 1);
	}
	for (int i = 0; i < m; i++) {
		if ((done[a[i]].second == 1 && i + 1 - done[a[i]].first > 0) || done[a[i]].second == 0 || (done[a[i]].second == 2 &&
			i + 1 - done[a[i]].first > 1)) {
			done[a[i]].first = i + 1;
			done[a[i]].second = 1;
			chrono[a[i]]++; 
		}
		else {
			for (int j = 1; j <= n; j++) {
				auto l = s[j].lower_bound(i + 1);
				auto r = s[j].upper_bound(i + 1);
				if ((*r - *l > 1 && done[j].second == 1 && i + 1 - done[j].first > 0) || done[j].second == 0 || 
					(done[j].second == 2 &&
			i + 1 - done[j].first > 1)) {
					done[j].first = *l;
					done[j].second = 2;
					chrono[j] += 2;
					break;
				}
			}                      
		}
	}
	int time = 0;
	for (int i = 1; i <= n; i++) {
		time = max(time, chrono[i]);
	}
	cout << time << '\n';
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
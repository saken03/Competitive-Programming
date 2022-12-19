/***
    AUTHOR:    shabylkhan
    CREATED:   06.06.2022 15:24:16

***/

#include<bits/stdc++.h>

using namespace std;

template<typename T>
bool intersect(T a, T b) {                               
	return a.first < b.first && a.second < b.second && a.second > b.first;
}

void solve() {
	string s;
	cin >> s;
	vector<pair<int, int>> cross(26, pair<int, int> {-1, -1});
	for (int i = 0; i < 52; i++) {
		if (cross[s[i] - 'A'].first == -1) cross[s[i] - 'A'].first = i;
		else cross[s[i] - 'A'].second = i;
	}

	int ans = 0;

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (intersect(cross[i], cross[j])) {
				ans++;
			}                                                                                                                   
		}
	}
	cout << ans;
}

int main() {
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
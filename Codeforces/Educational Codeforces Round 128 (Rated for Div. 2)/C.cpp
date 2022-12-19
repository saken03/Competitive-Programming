#include<bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;

	int n = (int)s.size();
	vector<pair<int, int>> comp;

	vector<int> pref1(n, 0), pref0(n, 0);
	int zeros = 0;

	bool line = 0, ind = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (i == 0) pref1[i] = 1;
			else pref1[i] = pref1[i - 1] + 1;
		}
		if (s[i] == '0') {
			if (i == 0) pref0[i] = 1;
			else pref0[i] = pref0[i - 1] + 1;
		}
		

		if (s[i] == '0') {
			zeros++;
			if (!line) ind = i;
			line = 1;
		}
		else {
			if (line) {
				comp.push_back({ind, i - 1});
			}
			line = 0;
		}
	}

	vector<int> ref0(n + 1, 0), ref1(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			if (i != n - 1) ref0[i] = ref0[i + 1] + 1;
			else ref0[i] = 1;
		}
		if (s[i] == '1') {
			if (i != n - 1) ref1[i] = ref1[i + 1] + 1;
			else ref1[i] = 1;
		}
	}

	vector<pair<int, int>> comp2 = comp;
	reverse(comp2.begin(), comp2.end());

	int ans = zeros;
	for (int i = 0; i <= (int)comp.size(); i++) {
		int j = (int)comp.size() - i;

		int zz = zeros;
		int on = 0;

		if (i != 0) {
			zz -= pref0[comp[i - 1].second];
			on += pref1[comp[i - 1].first];
		}
		if (j != 0) {
			zz -= pref0[comp2[j - 1].first];
			on += pref1[comp2[j - 1].first];
		}
		
		ans = min(ans, max(zz, on));
	}
	cout << ans << '\n';
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
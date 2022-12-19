/***
    AUTHOR:    shabylkhan
    CREATED:   14.06.2022 20:46:21
 
***/
 
#include<bits/stdc++.h>
 
using namespace std;
 
map<int, int> m;
 
bool comp(int a, int b) {
	return m[a] > m[b];
}
 
void solve() {
	int n;
	cin >> n;
	m.clear();
	set<int> s;
	for (int i = 0; i < n; i++) {
	  int x;
	  cin >> x;
	  s.insert(x);
		m[x]++;
	}
 
	vector<int> a;
 
	for (auto it : s) {
		a.push_back(it);
	}
 
	sort(a.begin(), a.end(), comp);

	int mx = n;
	map<int, int> mm; int cc = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		while (m[a[i]] > 1) {
			m[a[i]]--;
			cnt++;
			mm[cnt]++;
			mx--;
		}
		cc = max(cc, cnt);
	}
	int ans = mx;
	for (int i = 1; i <= cc; i++) {
		if (mm[i] & 1) ans--;
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
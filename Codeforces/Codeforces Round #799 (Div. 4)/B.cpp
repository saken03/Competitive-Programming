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
 
	/*cout << "Sorted array is: ";
	for (int i : a) cout << i << ' ';
	cout << '\n'; */
 
	int i = 0, j = 1, sz = n;
	n = (int)s.size();
	while (m[a[i]] > 1 || m[a[j]] > 1) {
		m[a[i]]--;
		m[a[j]]--;
		sz -= 2;
		if (m[a[i]] < 2 && i != n - 3) i += 2;
		if (m[a[j]] < 2 && j != n - 2) j += 2;
	}
	cout << sz << '\n';
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
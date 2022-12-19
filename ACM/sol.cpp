#include<bits/stdc++.h>

#define sz(x) (int)(x).size()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> m, ans;
	int mx = 0;
	for (int& i : a) {
		cin >> i;
		mx = max(mx, i);
		m[i]++;
	}
	for (int& i : a) {
		ans[i] += m[i] - 1;
		for (int j = i + i; j <= mx; j += i) {
		  if (m[j]) {
				ans[i] += m[j];
				ans[j] += m[i];  
		  }
		}
	}

	for (int& i : a) cout << ans[i] << ' ';
}

int main() {                                                                       
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
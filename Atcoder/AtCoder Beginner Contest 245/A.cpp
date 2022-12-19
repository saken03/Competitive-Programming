#include<bits/stdc++.h>

using namespace std;


void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (make_pair(a, b) <= make_pair(c, d) ? "Takahashi" : "Aoki");
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

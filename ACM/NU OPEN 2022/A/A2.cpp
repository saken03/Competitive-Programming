#include<bits/stdc++.h>

using namespace std;

void solve() {
	long long m;
	cin >> m;
/*
	for (int i = 1; i * i <= m; i++) {
		if (i * i == m) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
*/
	if (int(sqrt(m)) * 1ll * int(sqrt(m)) == m) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios::sync_with_stdio(0);   
	cin.tie(0);
	
	solve();

	return 0;
} 
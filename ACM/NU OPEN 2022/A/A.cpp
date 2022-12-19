#include<bits/stdc++.h>

using namespace std;

void solve() {
	int m;
	cin >> m;
	int n = 0, l = 0, i = 1;
	while (n < m) {
		n = l + i * 2 - 1;
		i++;
		l = n;
	}
	cout << n;
//	cout << (n == m ? "Yes" : "No") << '\n';
}

int main() {
	ios::sync_with_stdio(0);   
	cin.tie(0);
	
	solve();

	return 0;
} 
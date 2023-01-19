#include<bits/stdc++.h>
using namespace std;

const int INF = (int)1e10;

int n, r[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> r[i];

	int ans = INF;	
	for (int i = 0; i < n; i++) {
		int cur = 0;
		for (int pos = 0; pos < n; pos++) {
			cur += pos * r[(i + pos) % n];
		}
		ans = min(ans, cur);
	}

	cout << ans;

	return 0;
}
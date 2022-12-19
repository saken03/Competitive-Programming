#include<bits/stdc++.h>
using namespace std;
  
void solve() {
	int n;
	cin >> n;
	
	vector<vector<int>> g(n, vector<int> (n));
	vector<int> in(n), out(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x) {
				out[i]++;
				in[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << in[i] << ' ' << out[i] << '\n';
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  freopen("half-degree.in", "r", stdin);
	freopen("half-degree.out", "w", stdout);
	solve();
	return 0;
}
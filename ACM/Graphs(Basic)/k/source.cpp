#include<bits/stdc++.h>

#define pb push_back

using namespace std;
  
int in[105], out[105];

void solve() {
	int n;
	cin >> n;   
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x) out[i]++, in[j]++;
		}
	}	
	
	vector<int> v1, v2;

	for (int i = 0; i < n; i++) {
		if (!in[i]) v1.pb(i + 1);
	}
	for (int i = 0; i < n; i++) {
		if (!out[i]) v2.pb(i + 1);
	}

	cout << (int)v1.size() << '\n';
	for (int i : v1) cout << i << ' ';
	cout << '\n';
	cout << (int)v2.size() << '\n';
	for (int i : v2) cout << i << ' ';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  freopen("source.in", "r", stdin);
	freopen("source.out", "w", stdout);
	solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, b;
	cin >> n >> b;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}             
	
	queue<ll> q;
	ll last = 0;
	for (int i = 1; i <= n; i++) {
		ll t, d;
		cin >> t >> d;
		while (!q.empty() && q.front() <= t) {
			q.pop();
		}


	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
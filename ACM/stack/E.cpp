#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e12;

void solve() {
	int n;
	cin >> n;
	
	vector<ll> a(n + 2);
	vector<int> left(n + 1), right(n + 1);
	stack<int> t;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	a[0] = a[n + 1] = -1;
	t.push(0);
	
	for (int i = 1; i <= n; i++) {
		while (a[t.top()] >= a[i]) t.pop();
		left[i] = t.top();
		t.push(i);
	}

	while (!t.empty()) t.pop();
	t.push(n + 1);

	vector<int> ans(n + 2);
	
	for (int i = n; i >= 1; i--) {
		while (a[t.top()] > a[i]) t.pop();
		right[i] = t.top();
		t.push(i);
		int len = right[i] - left[i] - 1;
		ans[len] = max(ans[len] + 0ll, a[i]);
	}

	for (int i = n - 1; i >= 1; i--) {
		ans[i] = max(ans[i], ans[i + 1]);
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}              	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();

	return 0;
}
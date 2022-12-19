#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	stack<int> st;
	vector<int> near(n);
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		if (st.empty()) near[i] = -1;
		else near[i] = st.top();
		st.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << near[i] + 1 << ' ';
	}
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
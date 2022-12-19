#include<bits/stdc++.h>
using namespace std;

const int INF = 1e8;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	stack<int> st;
	vector<int> left_mn(n + 1), left_mx(n + 1), right_mn(n + 1), right_mx(n + 1);
	st.push(0);
	a[0] = -1;
	for (int i = 1; i <= n; i++) {
		while (a[st.top()] > a[i]) st.pop();
		left_mn[i] = st.top();
		st.push(i);
	}          
	while (!st.empty()) st.pop();
	st.push(n + 1);
	a[n + 1] = -1;
	for (int i = n; i >= 1; i--) {
		while (a[st.top()] >= a[i]) st.pop();
		right_mn[i] = st.top();
		st.push(i);
	}
/*
	cout << "left[i]: ";
	for (int i = 1; i <= n; i++) {
		cout << left_mn[i] << ' ';
	}
	cout << "\nright[i]: ";
	for (int i = 1; i <= n; i++) {
		cout << right_mn[i] << ' ';
	}
	return;
*/
	while (!st.empty()) st.pop();
	st.push(0);
	a[0] = INF;
	for (int i = 1; i <= n; i++) {
		while (a[st.top()] < a[i]) st.pop();
		left_mx[i] = st.top();
		st.push(i);
	}

	while (!st.empty()) st.pop();
	st.push(n + 1);
	a[n + 1] = INF;
	for (int i = n; i >= 1; i--) {
		while (a[st.top()] <= a[i]) st.pop();
		right_mx[i] = st.top();
		st.push(i);
	}
/*
	cout << "left[i]: ";
	for (int i = 1; i <= n; i++) {
		cout << left_mx[i] << ' ';
	}
	cout << "\nright[i]: ";
	for (int i = 1; i <= n; i++) {
		cout << right_mx[i] << ' ';
	}
*/
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i] * 1ll * (right_mx[i] - i) * (i - left_mx[i]);
		ans -= a[i] * 1ll * (right_mn[i] - i) * (i - left_mn[i]);
	}
	cout << ans << '\n';
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
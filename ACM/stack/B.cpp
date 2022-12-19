#include<bits/stdc++.h>

#define ll long long;

using namespace std;

const int MAXN = 2e5 + 100;
const int INF = 1e8;

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n + 2), left(n + 1), right(n + 1);
	map<int, int> pos;

	a[0] = INF;
	a[n + 1] = INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	stack<int> st;
	
	st.push(0);
	for (int i = 1; i <= n; i++) {
		while (a[st.top()] < a[i]) st.pop();
		left[i] = st.top();
		st.push(i);
	}       
	
	while (!st.empty()) st.pop();
	
	st.push(n + 1);
	for (int i = n; i >= 1; i--) {
		while (a[st.top()] < a[i]) st.pop();
		right[i] = st.top();
		st.push(i);
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int lenl = i - left[i] - 1;
		int lenr = right[i] - i - 1;
		if (lenl < lenr) {	
			for (int j = left[i] + 1; j < i; j++) {
				int need = a[i] - a[j];
				if (pos[need] > i && pos[need] < right[i]) sum++;
			}
		}
		else {
			for (int j = i + 1; j < right[i]; j++) {
				int need = a[i] - a[j];
				if( pos[need] < i && pos[need] > left[i]) sum++;
			}
		}
	}

	cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
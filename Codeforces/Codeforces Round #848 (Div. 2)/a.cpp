#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	bool case1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] + a[i + 1] == -2) {
			cout << sum + 4 << '\n';
			return;
		}
		if (a[i] == -1) {
			case1 = 1;
		}
	}                             
	if (case1) cout << sum;
	else cout << sum - 4;
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) 
		solve();
	return 0;
}







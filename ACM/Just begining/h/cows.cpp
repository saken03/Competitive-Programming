#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int INF = (int)1e9;

int n, k, a[10005];

bool check(int x) {
	int last = a[0], c = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - last >= x) {
			c++;
			last = a[i];
		}
		if (c == k) return 1;
	}
	return 0;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	int l = 1, r = INF, ans = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}

int main() {
	setIO("cows");
	solve();
	return 0;
} 

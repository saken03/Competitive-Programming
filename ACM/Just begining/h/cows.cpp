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

const int INF = (int)1e12;

int n, k, ans;
vector<int> a;

int calc(vector<int> a) {
	int mn = a[1] - a[0];
	for (int i = 2; i < n; i++) mn = min(mn, a[i] - a[i - 1]);
	return mn;
}

void rec(int pos, vector<int> v = {}) {
	if (pos > n) return;
	if (sz(v) == k) {
		ans = max(ans, calc(v));
		return;
	}
	vector<int> t = v;
	t.pb(a[pos]);
	rec(pos + 1, t);
	rec(pos + 1, v);
}

void solve() {
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	rec(0);
	cout << ans;
}

int main() {
	setIO("cows");
	solve();
	return 0;
} 

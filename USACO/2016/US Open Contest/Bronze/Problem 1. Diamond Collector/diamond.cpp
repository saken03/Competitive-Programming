/***
PROB: 
LANG: C++14
username: sakenseri1
***/
/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

***/
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

void solve() {        
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i; j < n; j++) {
			if (abs(a[i] - a[j]) > k) {
				break;
			}
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}

int main() {
	setIO("diamond");

	solve();

	return 0;
}   

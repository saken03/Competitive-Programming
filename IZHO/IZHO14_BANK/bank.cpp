/***
PROB: 
LANG: C++14
username: sakenseri1
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	vector<bool> cash(20005);
	cash[0] = 1;
	for (int msk = 1; msk < (1 << m); msk++) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			if (msk & (1 << i)) 
				sum += b[i];
		}
		cash[sum] = 1;
	}
	
	bool good = 1;
	for (int i = 0; i < n; i++) {
		if (cash[a[i]] == 0) {
			good = 0;
			break;
		}
	}
	cout << (good ? "YES" : "NO") << '\n';
}

int main() {
	setIO("");

	solve();

	return 0;
}   

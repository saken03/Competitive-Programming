/***
PROB: ariprog
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

int n, m;
int bq[2*251*251];

bool check(int s, int d) {
	for (int i = 0; i < n; i++) {
		if (!bq[s+i*d]) 	
			return 0;
	}
	return 1;
}

void solve() {        
	cin >> n >> m;

	for (int p = 0; p <= m; p++) 
		for (int q = 0; q <= m; q++) 
			bq[p*p + q*q] = 1;
		

	vector<pair<int, int>> v;
	int m2 = 2*m*m;
	
	for (int s = 0; s <= m2; s++) 
		for (int d = 1; d <= (m2 - s) / (n - 1); d++) 
			if (check(s, d))
				v.pb({d, s});
	
	sort(v.begin(), v.end());
	for (auto i : v) 
		cout << i.s << ' ' << i.f << '\n';
	if (v.empty()) 
		cout << "NONE\n";
}

int main() {
	setIO("ariprog");

	solve();

	return 0;
}   

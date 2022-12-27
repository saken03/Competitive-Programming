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
	int n;
	cin >> n; 
	map<int, bool> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		m[x] = 1;
	}
	cout << sz(m);
}

int main() {
	setIO("differ");

	solve();
	
	return 0;
} 












/***
PROB: combo 
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

int n;
vector<int> f, m;

bool close(int a, int b) {
	if (abs(a - b) <= 2 || abs(a - b) >= n - 2) return 1;
	return 0;
}

bool close_enough(vector<int> a, vector<int> b) {
	return close(a[0], b[0]) && close(a[1], b[1]) && close(a[2], b[2]);
}

void solve() {        
	cin >> n;
	f.resize(n);
	m.resize(n);
	for (int i = 0; i < 3; i++) cin >> f[i];
	for (int i = 0; i < 3; i++) cin >> m[i];
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			for (int k = 1; k <= n; k++) {
				vector<int> a(3);
				a[0] = i;
				a[1] = j;
				a[2] = k;
				if (close_enough(a, f) || close_enough(a, m)) cnt++;
			}
	cout << cnt << '\n';
}

int main() {
	setIO("combo");

	solve();

	return 0;
}   

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

int c[1005], v[1005];

bool cmp(int& a, int& b) {
	int q = c[a], w = c[b];
	q = (q + v[a]) / v[a];
	w = (w + v[b]) / v[b];
	if (c[a] < v[a]) return 1;
	if (c[b] < v[b]) return 1;
	if (q < w) return 1;
	return 0;
}

void solve() {                         
	int n;               
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> v[i];
//		assert(c[i] / v[i] != 0);
	}
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), cmp);
	for (int i : ord) cout << i + 1 << ' ';
}

int main() {                      	
	setIO("balloons");

	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 

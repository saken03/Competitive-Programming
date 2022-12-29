#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MAXN = 1e5 + 123;
const int INF = (int)1e12;
                                       
void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	map<int, int> a, b, c;
	for (int i = 0; i < n; i++) { int x; cin >> x; a[x]++; }
	for (int i = 0; i < m; i++) { int x; cin >> x; b[x]++; }
	for (int i = 0; i < k; i++) { int x; cin >> x; c[x]++; }
	vector<int> v;
	for (auto q : a) {
		for (auto w : b) {
			for (auto e : c) {
				if (q.f == w.f && w.f == e.f) {
					for (int i = 0; i < min(q.s, min(w.s, e.s)); i++) {
						v.pb(w.f);
					}
				}
			}
		}
	}
	cout << sz(v) << '\n';
	for (auto i : v) cout << i << ' ';
}
                                           
int main() {
	setIO("cinema");

	int tt = 1;
//	cin >> tt;
	while (tt--) { 
		solve();
	}

	return 0;
} 

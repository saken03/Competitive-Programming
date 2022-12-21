#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n), p(n);
	for (int& i : h) cin >> i;
	for (int& i : p) cin >> i;

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y) { return p[x] < p[y]; });

	int dmg = 0;
	for (int i : ord) {
		if (h[i] <= dmg) 
			continue;

		if (i != ord[0]) 
			k -= p[i];

		if (k > 0) {
			dmg += k;
			while (h[i] > dmg) {
				k -= p[i];
				if (k < 0) 
					break;
				dmg += k;	
			}
		}	

		if (h[i] > dmg) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 

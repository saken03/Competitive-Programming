#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i], p[i]--;

	int ind = 1, ans = 0;
	vector<int> comp(n);
	for (int i = 0; i < n; i++) {
		if (comp[i]) continue;
		int v = i;
		while (comp[v] == 0) {
			comp[v] = ind;
			v = p[v];
			ans++;
		}
		ind++;
		ans--;
	}                             

	for (int i = 0; i < n - 1; i++) {
		if (comp[i] == comp[i + 1]) {
			cout << ans - 1 << '\n';
			return;
		}
	}
	cout << ans + 1 << '\n';
}
                               f
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

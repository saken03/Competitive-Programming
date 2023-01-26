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
	int c1 = 0, c0 = 0;
	vector<int> a(n);
	vector<int> v1, v0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int x = a[i] % 2;
		if (x) c1++, v1.pb(i + 1);
		else c0++, v0.pb(i + 1);
	}
	if (c1 && c0 > 1) {
		cout << "YES\n";
		cout << v1[0] << ' ' << v0[0] << ' ' << v0[1] << '\n';
	}
	else if (c1 >= 3) {
		cout << "YES\n";
		for (int i = 0; i < 3; i++) {
			cout << v1[i] << ' ';
		}
		cout << '\n';
	} 
	else cout << "NO\n";
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

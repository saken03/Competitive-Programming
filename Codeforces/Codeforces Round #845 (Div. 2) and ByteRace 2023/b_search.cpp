#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MOD = (int)1e9 + 7;

ll sum(ll n) {
	return (n * n + n) / 2ll;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = i + 1;
	int ans = 0;

	do {
		vector<int> b(n + n);
		for (int i = 0; i < n; i++) 
			b[i] = a[i];
		vector<int> t = a;
		reverse(t.begin(), t.end());
		for (int i = 0; i < n; i++) 
			b[n + i] = t[i];

/*
		for (int i = 0; i < n + n; i++) {
			cout << b[i] << ' ';
		}   
		cout << '\n';
*/
		int cnt = 0;
		for (int i = 0; i < n + n; i++) {
			for (int j = i + 1; j < n + n; j++) {
				if (b[i] > b[j]) cnt++;
			}
		}
		ans += cnt;
		cout << cnt << '\n';
	} while (next_permutation(a.begin(), a.end()));

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 

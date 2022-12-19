#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	ll com = n / k, fri = n % k;  
	for (int i = 0; i < m; i++) {
		if (a[i] - 1 > com) {
			cout << "NO\n";
			return;
		}      
		else if (a[i] - 1 == com && fri) {
			fri--;
		}
		else if (a[i] - 1 == com && !fri) {
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

#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MOD = 998244353;

bool bit(int a, int b) {
	return a & (1 << b);
}

int n;
int a[105][105];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		vector<bool> was(2);
		if (a[i][i] == 2) {
			cout << 0 << '\n';
			return;
		}
		for (int j = i; j < n; j++) {
			if (a[i][j] == 1 && was[2]) {
				cout << 0 << '\n';
				return;
			}
			if (a[i][j] == 2) was[2] = 1;
		}
	}

	vector<int> b(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (b[j] == -1) b[j] = a[i][j];
			else {
				if (a[i][j] == 1 && i + 1 <= j) b[j] = 1;
				else if (a[i][j] == 2) b[j] = min(b[j], a[i][j]);
			}
		}
	}

 	ll ans = 0;
 	vector<int> sp(n);
  	int k = 0;
  	vector<int> was(2);
  	for (int j = 0; j < n; j++) {
  		if (b[j] == 0) {
  			k++;
  			sp[j] = 2;
  		}
  		else if (b[j] == 1) {
  			k = 1;
  			if (was[1]) sp[j] = 1;
  			else sp[j] = 2, was[1] = 1;
  		}
  		else {
  			ans += (1 << k) + (1 << k) - 2;
  			ans %= MOD;
  		}
  	} 
 
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

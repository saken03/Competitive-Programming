/***
    AUTHOR:    shabylkhan
    CREATED:   12.06.2022 13:19:39

***/

#include<bits/stdc++.h>

using namespace std;



void solve() {
	long long a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	long long ans = __gcd(a, b);

	vector<long long> div;
	for (int i = 1; i * i <= b; i++) {
		if (b % i == 0) {
			div.push_back(i);
			if (i * 1ll * i != b) {
				div.push_back(b / i);
			}
		}
	}
       
  for (int d : div) {
  	if (isPrime(d)) {
  		ans = max(ans, __gcd(a * d, b));
  	}
  }
  cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i < 

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 
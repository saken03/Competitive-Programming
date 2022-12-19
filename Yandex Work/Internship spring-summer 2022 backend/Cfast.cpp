/***
    AUTHOR:    shabylkhan
    CREATED:   12.06.2022 14:59:54

***/

#include<bits/stdc++.h>

using namespace std;

bool prime(long long n) {
	if (n < 2) return 0;
	for (long long i = 2; i * 1ll * i <= n; i++) if (n % i == 0) return 0;
	return 1;
}
             
void solve() {
	long long a, b;
	cin >> a >> b;

	long long g = __gcd(a, b);
	while (__gcd(a, b) != 1) {
		a /= g;
		b /= g;
	}
                      
  if (a > b) swap(a, b);

  long long ans = g;
  if (prime(b)) ans = max(ans, g * b);
  if (prime(a)) ans = max(ans, g * a);
  vector<long long> div;
	for (long long i = 2; i * 1ll * i <= b; i++) {
		if (b % i == 0) {
			div.push_back(i);
			if (i * 1ll * i != b) {
				div.push_back(b / i);
			}
		}                                    
	}
	for (long long d : div) {
		if (prime(d)) {
			ans = max(ans, g * d);
		}  
	}
	div.clear();
	for (long long i = 2; i * 1ll * i <= a; i++) {
		if (a % i == 0) {
			div.push_back(i);
			if (i * 1ll * i != a) {
				div.push_back(a / i);
			}
		}                                    
	}
	for (long long d : div) {
		if (prime(d)) {
			ans = max(ans, g * d);
		}  
	}

	cout << ans << '\n';
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
#include<bits/stdc++.h>

#define ll long long

using namespace std;

bool good(long long k, long long f) {
	ll cur = k;
	while (k) {
		cur *= k % 10;         
		k /= 10;
	}                       
	return (cur == f ? 1 : 0);
}

void solve() {
	long long n;
	long long f;
	cin >> n >> f; n--;
	if (n == 0 && f == 0) {
		cout << 0 << '\n';
		return;
	}
	long long x = 1;
	while (n--) {
		x *= 10;
	}       
	for (long long i = x; i < x * 10; i++) {
		if (good(i, f)) {
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(0);   
	cin.tie(0);
	
	solve();

	return 0;
} 
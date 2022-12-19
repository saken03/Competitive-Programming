/***
    AUTHOR:    shabylkhan
    CREATED:   13.10.2022 20:59:31

***/

#include<bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
	ll n, m;
	cin >> n >> m;
	int x = n % 10;
	int k = x & 1;
	if (k) k = 10;
	else k = 5;
	if (x == 5) k = 2;
	cout << (n * (m / k) * k) << '\n';
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

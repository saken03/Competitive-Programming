#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n;
	cin >> n;
	ll x = 1, ch = 10, cnt = 0;
	while (x <= n) {
		cnt++;
		x += ch / 10;
		if (x == ch) ch *= 10;
	}
	cout << cnt << '\n';
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

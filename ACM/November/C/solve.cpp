#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

void no() {
	cout << "NO\n";
	exit(0);
}

void yes() {
	cout << "YES\n";
	exit(0);
}

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000};

bool bit(int a, int b) {
	return a & (1 << b);
}

void solve() {        
	int x, y;
	cin >> x >> y;
	if (x < y) {
		no(); 
	} 
	int n = 14;
	for (int m = 0; m < (1 << n); m++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (bit(m, i)) sum += coins[i]; 
		}
		if (sum == y) yes();
	}
	no();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	solve();
	return 0;
}
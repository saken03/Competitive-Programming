#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
              
typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;
const int MAXN = 1e6;

int n, m;

int rec(int k, int sum) {
	if (sum > m || k > n) return 0;
	if (k == n && sum == m) {
		return 1;
	}
	int cnt = 0;
	for (int i = 0; i <= m; i++) {
		cnt = cnt + rec(k + 1, sum + i) % MOD;
	}
	return cnt;
}

void solve() {	
	cin >> n >> m;
	cout << rec(0, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  
  solve();

	return 0;
} 

#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int INF = (int)1e10;

void ckmax(ll& a, ll b) {
	a = max(a, b);
}

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	ll sum = 0;	

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	vector<vector<vector<vector<ll>>>> dp(n, vector<vector<vector<ll>>> (2, vector<vector<ll>> (2, vector<ll> (2, 0))));
	

	for (int i = 2; i < n; i++) {
		ll nsum = sum;
		nsum -= a[i] + a[i - 1] + a[i - 2];           
		ckmax(dp[i][1][1][1], nsum + a[i] + a[i + 1] + a[i + 2]);
		ckmax(dp[i][0][0][1], nsum - a[i] - a[i - 1] + a[i - 2]);
		ckmax(dp[i][1][0][0], nsum + a[i] - a[i - 1] - a[i - 2]);
		ckmax(dp[i][0][1][0], nsum - a[i] + a[i - 1] - a[i - 2]);
	}

	for (int i = 3; i < n; i++) {
		
	}

	cout << max(max(dp[n - 1][1][1][1], dp[n - 1][0][0][1]), max(dp[n - 1][1][0][0], dp[n - 1][0][1][0])) << '\n';
}

int main() {                                                                                
	setIO("");                                                                                             
	
	int tt = 1;
	cin >> tt;
	while (tt--) 
		solve();

	return 0;
}   

#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MAXN = 1e5 + 123;
const int INF = (int)1e12;
                                       
void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve() {
	int n;
	cin >> n;
	rec(0);

/*
	dp[1][0] = 1;
	dp[1][1] = 1;
		
*/
}

int main() {
	setIO("ones");

	int tt = 1;
//	cin >> tt;
	while (tt--) { 
		solve();
	}

	return 0;
} 

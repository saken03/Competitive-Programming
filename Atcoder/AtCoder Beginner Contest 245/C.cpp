#include<bits/stdc++.h>

using namespace std;

int n, k;
int a[200005], b[200005];
bool dp[200005], ep[200005];

int good(int a, int b) {
	return abs(a - b) <= k;
}

void solve() {
	//cin >> n >> k;
	scanf("%d %d", &n, &k);
	
	for (int i = 1; i <= n; i++) {
	//	cin >> a[i];
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
	//	cin >> b[i];
		scanf("%d", &b[i]);
	}
		
	dp[1] = 1;
	ep[1] = 1;
	
	for (int i = 2; i <= n; i++) {	
		if (!(dp[i - 1] || ep[i - 1])) break; 
		
		if (dp[i - 1] && good(a[i - 1], a[i])) dp[i] = 1;
		if (dp[i - 1] && good(a[i - 1], b[i])) ep[i] = 1;
		if (ep[i - 1] && good(b[i - 1], a[i])) dp[i] = 1;
		if (ep[i - 1] && good(b[i - 1], b[i])) ep[i] = 1;
	}
	
	if (dp[n] || ep[n]) printf("%s", "Yes");
	else printf("%s", "No");
}

int main() {/*
	ios::sync_with_stdio(0);
	cin.tie(0);*/
	
	int tt = 1;
	while (tt--) {
		solve();
	}
	
	return 0;
}



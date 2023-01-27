#include<bits/stdc++.h>
using namespace std;

const int INF = (int)1e11;
const int N = 305;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	vector<vector<int>> dp(n, vector<int> (n));
	for (int i = n - 1; i >= 0; i--) 
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j])
				dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j - 1]);
			for (int k = i + 1; k < j; k++)
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);	
		}
	cout << n - dp[0][n - 1] << '\n';

	return 0; 
}
/***
    AUTHOR:    shabylkhan
    CREATED:   02.10.2022 09:35:22

***/

#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

void solve() {
	int n;

	cin >> n;

if (n <= 1e4) {
	vector<long long> a(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}	
	long long ans = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long A = a[i], B = a[j] - a[i], C = a[n] - a[j]; 
			ans = min(ans, max(A, max(B, C)) - min(A, min(B, C)));
		}
	}

	cout << ans << '\n';
}

else {
		long long s = 0;
	vector<int> a(n); for (int i = 0; i < n; i++) { cin >> a[i]; s += a[i]; }
	s++;
	s /= 3;
	vector<int> A(3, 0);
	int j = 0;
	long long cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i];
		if (j == 0) {
			if (cur >= s || i == n - 3) {
				A[j] = cur;
				cur = 0;
				j++;
			}
		}
		else if (j == 1) {
			if (cur >= s || i == n - 2) {
				A[j] = cur;
				cur = 0;
				j++;
			}
		}
		else {
			for (int k = i + 1; k < n; k++) {
				cur += a[k];
			}
			A[j] = cur;
			break;
		}
	}
	sort(A.begin(), A.end());
	cout << A[2] - A[0] << '\n';       
}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
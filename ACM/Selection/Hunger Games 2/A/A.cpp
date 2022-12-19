/***
    AUTHOR:    shabylkhan
    CREATED:   02.10.2022 12:37:38

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1e5 + 100;

int a[MAXN];
ANS ans;

struct ANS {
	int l;
	int r;
};
            
void segment(vector<int>& a) {
	int mul1 = 1, L1, R1;
	int l = 0, r = (int) a.size() - 1;
	for (int i = l; i <= r; i++) {
		if (a[i] < 0) {
			for (int j = i + 1; j <= r; j++) {
				mul1 *= a[j];
			}
			break;
		}
	}
	int mul2 = 1, L2, R2;
	for (int i = r; i >= l; i--) {
		if (a[i] < 0) {
			for (int j = i - 1; j >= l; j--) {
				mul2 *= a[j];
			}
			break;
		}
	}


}

void solve() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> pp;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
		  segment(pp);
			pp.clear();
		}
		else {
			pp.push_back(a[i]);
		}
	}

	cout << ans << '\n';
}

int main() {
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
/***
    AUTHOR:    shabylkhan
    CREATED:   02.10.2022 09:58:25

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int a[MAXN];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int k = 0; k < q; k++) {
		int l, r;
		cin >> l >> r;
		long long gA = 0, gB = 0, ans = 0;
		vector<int> aa, bb;
		for (int j = l; j <= r; j++) {
			if (gA <= gB) gA += a[j], aa.push_back(a[j]);
			else gB += a[j], bb.push_back(a[j]);	
		}
		if (gA == gB) {
			cout << gA << '\n';
			continue;
		}


		int i = 0, j = 1;
		bool ok = 0;
 	 	
 	 	if (gA > gB) {
			while (i < (int) aa.size() && j < aa.size() && gA > gB) {
				if (aa[i] && aa[j]) {
					aa[i]--;
					aa[j]--;
					gA -= 2;
					ans++;
					if (aa[i] == 0) i += 2;
					if (aa[j] == 0) j += 2;
				}
			}
			cout << ans + max(gA, gB) << '\n';
			ok = 1;
		}
		if (ok) continue;
		i = 0, j = 1;
		ans = 0;
	 if (gA < gB) {
			while (i < bb.size() && j < bb.size() && gA < gB) {
			if (bb[i] && bb[j]) {
				bb[i]--;
				bb[j]--;
				gB -= 2;
				ans++;
				if (bb[i] == 0) i += 2;
				if (bb[j] == 0) j += 2;
			}
  		cout << ans + max(gA, gB) << '\n';
			}
	 }
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
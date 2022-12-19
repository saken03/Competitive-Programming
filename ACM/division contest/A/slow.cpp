/***
    AUTHOR:    shabylkhan
    CREATED:   26.10.2022 19:15:16

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 123;

int a[MAXN];

void build(int v, int tl, int tr) {
	
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {	
		cin >> a[i];
	}
	build(1, 1, n);  
	while (q--) {
		int tp, x;
		cin >> tp >> x;
		if (tp == 1) {
			
		}
		else {
			
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
} 
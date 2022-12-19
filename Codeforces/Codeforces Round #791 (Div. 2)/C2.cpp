#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 123;

int tx[4 * MAXN], ty[4 * 	MAXN];
  
void update(int tp, int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		if (tp == 1) tx[v] += x;
		if (tp == 2) ty[v] += x;
		
		return;
	}

	int tm = (tl + tr) >> 1;
	if (tm <= pos) 
		update(tp, v + v, tl, tm, pos, x);
	else 
		update(tp, v + v + 1, tm + 1, tr, pos, x);
	
	if (tp == 1) tx[v] = tx[v + v] + tx[v + v + 1];
	if (tp == 2) ty[v] = ty[v + v] + ty[v + v + 1];
}

int Sum(int tp, int v, int tl, int tr, int l, int r) {
	if (tl == tr) {
		if (tp == 1) return tx[v];
		if (tp == 2) return ty[v];
	}
	
	if (l <= tl && tr <= r) { 
		if (tp == 1) return tx[v];
		if (tp == 2) return ty[v];
	}
	
	if (r < tl || l > tr) 
		return 0;

	int tm = (tl + tr) >> 1; 
	return Sum(tp, v + v, tl, tm, l, min(r, tm)) + Sum(tp, v + v + 1, tm + 1, tr, max(l, tm + 1), tr);
}

void solve() {
	int n, q;
	cin >> n >> q;
	
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			update(1, 1, 1, n, x, 1);
			update(2, 1, 1, n, y, 1);
		}
		else if (t == 2) {
			int x, y;
			cin >> x >> y;			
			update(1, 1, 1, n, x, -1);
			update(2, 1, 1, n, y, -1);
		}
		else {
			int x2, y2, x1, y1;
			cin >> x1 >> y1 >> x2 >> y2;
			
			if ((Sum(1, 1, 1, n, x1, x2) == x2 - x1 + 1) || (Sum(2, 1, 1, n, y1, y2) == y2 - y1 + 1)) {
				cout << "Yes\n";
			}
			else cout << "No\n";
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
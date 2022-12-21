#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

int n, vl[1005], vr[1005], p[1005];

void build(int v) {
	if (v > n) return;
	if (v + v <= n) vl[v] = v + v, p[v + v] = v;
	if (v + v + 1 <= n) vr[v] = v + v + 1, p[v + v + 1] = v;
	build(v + v);
	build(v + v + 1);	
}

void out(int v) {
	if (v > n) return;
	out(vl[v]);
	cout << v << ' ';
	out(vr[v]);
}

void solve() {
	int q;
	cin >> n >> q;

	for (int i = 1; i <= 1000; i++) {
		vl[i] = vr[i] = p[i] = 0;
	}

	build(1);
	out(1);
	return;
	for (int i = 0; i < q; i++) {
		int v;
		cin >> v;
		if (!p[v]) continue;
		if (v == vl[p[v]]) {
			int x = vl[v];
			vl[v] = p[v];
			vl[p[v]] = x;
		}
		if (v == vr[p[v]]) {
			int x = vr[v];
			vr[v] = p[v];
			vr[p[v]] = x;
		}
		if (p[p[v]]) {
			if (p[v] == vl[p[p[v]]]) {
				vl[p[p[v]]] = v;
				int x = p[v];
				p[v] = p[p[v]];
				p[x] = v;
			}
			else {
				vr[p[p[v]]] = v;
				int x = p[v];
				p[v] = p[p[v]];
				p[x] = v;
			}
		}
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (!p[i]) {
			root = i;
			break;
		}
	}
	cout << root << '\n';return;
	out(root);
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

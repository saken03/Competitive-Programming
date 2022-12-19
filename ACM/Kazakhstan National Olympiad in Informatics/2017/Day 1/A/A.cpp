#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 123;

int n;
long long fenw[MAXN];

int lsb(int pos) {
	return pos & -pos;
}

void upd(int pos, int val) {
	while (pos <= n) {
		 fenw[pos] += val;
		 pos += lsb(pos);
	}
}

long long get(int pos) {
	long long sum = 0;
	while (pos > 0) {
		sum += fenw[pos];
		pos -= lsb(pos);
	}
	return sum;
}

int w[MAXN];

void solve() {
	cin >> n;

	int ind = 1;
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			cin >> w[ind];
			upd(ind, w[ind]);
			ind++;
		}
		else {
			int x;
			cin >> x;
			cout << get(x - 1) << '\n';
			upd(x, -w[ind - 1]);
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

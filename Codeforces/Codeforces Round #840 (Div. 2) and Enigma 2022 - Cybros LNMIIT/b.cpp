#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> hp(n);
	for (int i = 0; i < n; i++) {
		cin >> hp[i].s;
	}
	for (int i = 0; i < n; i++) {
		cin >> hp[i].f;
	}

	sort(hp.begin(), hp.end());

	for (int i = 0; i < n; i++) {
		while 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 

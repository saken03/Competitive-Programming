#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	bool good = 1;
	for (int i = 1; i <= n; i++) {
		if (i + i <= n && a[i] > a[i + i]) good = 0; 
		if (i + i + 1 <= n && a[i] > a[i + i + 1]) good = 0;
		if (!good) break;
	}
	cout << (good ? "YES" : "NO") << '\n';
}

int main() {
	setIO("isheap");
	solve();
	return 0;
} 

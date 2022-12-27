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
	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());
	int m;
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		int l = 0, r = n - 1;
		bool found = false;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] < x) {
				l = mid + 1;
			}
			else if (a[mid] > x) r = mid - 1;
			else {
				found = 1;
				break;
			}
		}
		cout << (found ? "YES" : "NO") << '\n';
	}
}

int main() {
	setIO("collect");
	solve();
	return 0;
} 

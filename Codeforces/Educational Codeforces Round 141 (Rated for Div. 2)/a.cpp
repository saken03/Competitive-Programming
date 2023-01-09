#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

// think..
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
	}
	vector<int> b;
	if (m[a[0]] > 1) {
		if (m[a[0]] < n) swap(a[1], a[m[a[0]]]);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum == a[i]) {
			cout << "NO\n";
			return;
		}
		sum += a[i];
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << '\n';
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

#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	string blank;
	getline(cin, blank);
	vector<int> a(3), b(3);
	map<int, int> x, y;
	for (int i = 0; i < 3; i++) {
		cin >> a[i] >> b[i];
		x[a[i]]++;
		y[b[i]]++;
	}	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if ((a[0] < a[1] && a[1] < a[2]) || (b[0] < b[1] && b[1] < b[2])) cout << "YES\n";
	else cout << "NO\n";
	return;
	for (int i = 0; i < 3; i++) {
		if (x[a[i]] == 1 || y[b[i]] == 1) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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

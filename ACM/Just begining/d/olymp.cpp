/***
PROB: 
LANG: C++14
username: sakenseri1
***/
/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

***/
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
	vector<pair<int, int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].f;
		a[i].s = i;
	}
	sort(a.rbegin(), a.rend() - 1);
	for (int i = 1; i <= n; i++) {
		cout << a[i].s << ' ';
	}
}

int main() {
	setIO("olymp");

	solve();

	return 0;
}   

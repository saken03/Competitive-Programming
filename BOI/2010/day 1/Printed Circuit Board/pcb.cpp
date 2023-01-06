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
/*
void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
*/
bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.f < b.f) 
		return 1;
	else
		return 0;	
}

void solve() {        
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].f >> a[i].s;
	}

	sort(a.begin(), a.end(), comp);
	reverse(a.begin(), a.end());
	
	vector<int> lis;
	for (int i = 0; i < n; i++) {
		int p = upper_bound(begin(lis), end(lis), a[i].s) - begin(lis);
		if (p == sz(lis)) 
			lis.pb(a[i].s);
		else
			lis[p] = a[i].s;	
	}
	cout << sz(lis) << '\n';
}

int main() {
//	setIO("pcb");

	solve();

	return 0;
}   

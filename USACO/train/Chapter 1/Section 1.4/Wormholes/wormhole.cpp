/***
PROB: wormhole
LANG: C++14
username: sakenseri1
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

const int N = 12;

int n, x[N + 1], y[N + 1];
int partner[N + 1], next_on_right[N + 1];

bool is_cycled() {
	for (int start = 1; start <= n; start++) {
		int pos = start;
		for (int count = 0; count < n; count++)
			pos = next_on_right[partner[pos]];
		if (pos != 0) return 1;
	}
	return 0;
}

int rec() {
	// find any wormhole without partner
	int i;
	for (i = 1; i <= n; i++) 
		if (partner[i] == 0)
			break;                                     
	
	// all wormholes paired?
	if (i > n) {
		return is_cycled();
	}

	int total = 0;
	// find partner for wormhole i
	for (int j = i + 1; j <= n; j++) 
		if (partner[j] == 0) {
			partner[i] = j;
			partner[j] = i;
			total += rec();
			partner[i] = partner[j] = 0;
		}
	return total;	
}

void solve() {        
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; i++) // calculate next warmhole to the right
		for (int j = 1; j <= n; j++)
			if (x[j] > x[i] && y[i] == y[j])
				if (next_on_right[i] == 0 || 
					x[j] - x[i] < x[next_on_right[i]] - x[i])
					next_on_right[i] = j;

	cout << rec() << '\n';
}

int main() {
	setIO("wormhole");

	solve();

	return 0;
}   

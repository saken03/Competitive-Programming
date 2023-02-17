#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

int n, m, p;

struct Port {
	int y;
	int b;
	int c;
};

struct Fishing {
	int x;
	int a;
};

const int MAXN = 1e5 + 10;

vector<Fishing> fish(MAXN);
vector<Port> port(MAXN);

bool comp(const Port &a, const Port &b) {
	return a.c > b.c;
}

void solve() {	
	cin >> n >> m >> p;

	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> fish[i].x >> fish[i].a;
		s += fish[i].a;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> port[i].y >> port[i].b >> port[i].c;
	}

	sort(port.begin(), port.end(), comp);
	
	ll cost = 0;
	int i = 0;
	while (s > 0 && i < m) {
		cost += min(s, port[i].b + 0ll) * port[i].c;
		s -= min(s, port[i].b + 0ll);
		i++;
	}

	cout << cost << '\n';
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

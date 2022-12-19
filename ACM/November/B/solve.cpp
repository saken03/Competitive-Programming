#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;
const int MAXN = 1e5 + 123;

int n, q;
int parent[MAXN], room[MAXN], room_head[MAXN];

void make_set(int v) {
	parent[v] = v;
	room_head[v] = v;
	room[v] = v;
}

int find_set(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	room_head[b] = room_head[a];
	parent[room_head[a]] = room_head[a];
	int aa = room_head[a];

}

void solve() {        
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		make_set(i);
	}
	for (int i = 0; i < q; i++) {
		int s, t;
		cin >> s >> t;
		union_sets(s, t);
	}
	for (int i = 1; i <= n; i++) {
		cout << room[find_set(i)] << ' ';
	}
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	solve();
	return 0;
}
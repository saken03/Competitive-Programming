/***
PROB: 
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

 
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int n, cnt, f[3], m[3];

bool check(vector<int> a) {
	bool g1 = 1, g2 = 1;
	for (int i = 0; i < 3; i++) {
		int v1 = a[i] - 2;
		int v2 = a[i] + 2;
		if (v1 < 1) v1 += n;
		if (v2 > n) v2 -= n;
		if (v1 > v2) swap(v1, v2);
		if (!(v1 <= f[i] && f[i] <= v2)) g1 = 0;
	}
	for (int i = 0; i < 3; i++) {
		int v1 = a[i] - 2;
		int v2 = a[i] + 2;
		if (v1 < 1) v1 += n;
		if (v2 > n) v2 -= n;
		if (v1 > v2) swap(v1, v2);
		if (!(v1 <= m[i] && m[i] <= v2)) g2 = 0;
	}
	if (g1 || g2) return 1;
	return 0;
}

void rec(vector<int> a) {
	if (sz(a) == 3) {               
		cnt += (check(a) ? 1 : 0);
//		if (check(a)) { for (int i : a) { cout << i << ' '; }; cout << '\n'; } 
		return;
	}
	for (int i = 1; i <= n; i++) {
		a.pb(i);
		rec(a);
		a.pop_back();
	}
}

void solve() {        
	cin >> n;
	for (int i = 0; i < 3; i++) cin >> f[i];
	for (int i = 0; i < 3; i++) cin >> m[i];
	
	vector<int> b;
	rec(b);
	cout << cnt << '\n';
}

int main() {
	setIO("combo");

	solve();

	return 0;
}   

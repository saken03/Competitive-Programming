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

string s, current;
int count[27]; 

void input() {
	cin >> s;
}

void clear() {
	for (int i = 0; i < 27; i++) 
		count[i] = 0;
}

void count() {
	for (int i = 0; i < 27; i++)
		count[i]++;
}

void solve(int l, int r) {

}

void solve() {
	input();
	clear(); // may be not needed
	count();
	solve(0, sz(s) - 1);		
}

int main() {
	setIO("");
	int tt = 1;
  cin >> tt;
	while (tt--)
		solve();
	return 0;
}
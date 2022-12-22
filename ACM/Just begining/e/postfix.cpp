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

bool isNum(string s) {
	for (char i : s) if (!(i >= '0' && i <= '9')) return 0;
	return 1;
}

void solve() {
	string c; 
	stack<int> st;
	while (cin >> c) {
		if (isNum(c)) {
			int x = 0;
			for (int i = 0; i < sz(c); i++) {
			  x *= 10;
				x += c[i] - '0';
			}
			st.push(x);
			continue;
		}
		if (c == "+") {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(a + b);
		}
		if (c == "-") {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(b - a);
		}
		if (c == "*") {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(a * b);
		}
	}
	cout << st.top();
}

int main() {
	setIO("postfix");

	solve();

	return 0;
}   

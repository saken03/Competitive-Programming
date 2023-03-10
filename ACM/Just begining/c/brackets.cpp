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
	string s;
	cin >> s;
	
	stack<char> st;
	for (int i = 0; i < sz(s); i++) {
		char x = s[i];
		if (x == '(') st.push('(');
		else if (x == '[') st.push('[');
		else if (x == '{') st.push('{');
		else {
			if (st.empty()) {
				cout << "NO\n";
				return;
			}
			char top = st.top();
			if (x == ')' && top == '(') st.pop();
			else if (x == ']' && top == '[') st.pop();
			else if (x == '}' && top == '{') st.pop();
			else {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << (!st.empty() ? "NO" : "YES");
}

int main() {
	setIO("brackets");

	solve();

	return 0;
}   

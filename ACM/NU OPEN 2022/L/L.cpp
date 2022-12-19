#include<bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	if (n == 1) {
		cout << "No\n";
		return;
	}            	
	map<char, int> m;
	bool good = 1;
	for (char i : s) {
		m[i]++;
//		cout << i - 'A' << ' ';
	}
//	return; 
	if (s[0] == s[n - 1] && m[s[0]] > 2) good = 0;
	cout << (good ? "Yes" : "No") << '\n';
}

int main() {
	ios::sync_with_stdio(0);   
	cin.tie(0);
	
	solve();

	return 0;
} 
/***
    AUTHOR:    shabylkhan
    CREATED:   12.06.2022 12:12:11

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<string> pic;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		pic.push_back(s);
	}

	for (string& s : pic) {
		for (int i = 0; i < m; i++) {
			if (s[i] == '/') s[i] = 92;
			else if (s[i] == 92) s[i] = '/';
		}
	}
	
	reverse(pic.begin(), pic.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pic[i][j] == '/') pic[i][j] = 92;
			else if (pic[i][j] == 92) pic[i][j] = '/';
			if (pic[i][j] == '_' && pic[i + 1][j] != '.') pic[i - 1][j] = '_', pic[i][j] = pic[i + 1][j], pic[i + 1][j] = ' '; 
			else if (pic[i][j] == '_') pic[i - 1][j] = '_', pic[i][j] = '.';
		}
	}		

  for (int i = 0; i < m; i++) cout << '.';
  cout << '\n';                            
	for (int i = 0; i < n - 1; i++) cout << pic[i] << '\n';
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
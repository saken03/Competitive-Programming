/***
PROB: crypt1
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

int n, num[100500];
bool has[10];

bool mult(int a, int b, int c, int d, int e) {
	vector<int> p1(4), p2(4), p3(5);
	p1[0] = c * e;
	p1[1] = b * e;
	p1[2] = a * e;
	p2[0] = c * d;
	p2[1] = b * d;
	p2[2] = a * d;

	p1[1] += p1[0] / 10;
	p1[0] %= 10;
	p1[2] += p1[1] / 10;
	p1[1] %= 10;
	p1[3] += p1[2] / 10;
	p1[2] %= 10;

	p2[1] += p2[0] / 10;
	p2[0] %= 10;
	p2[2] += p2[1] / 10;
	p2[1] %= 10;
	p2[3] += p2[2] / 10;
	p2[2] %= 10;

	for (int i = 0; i < 4; i++) {
		if (i == 3 && p1[i] == 0) continue;
		if (i == 3 && p2[i] == 0) continue;
		if (!has[p1[i]] || !has[p2[i]])
			return 0;
	} 

	p3[0] = p1[0];
	for (int i = 1; i < 4; i++) {
		p3[i] = p1[i] + p2[i - 1];
	}
	p3[4] = p2[3];

	p3[1] += p3[0] / 10;
	p3[0] %= 10;
	p3[2] += p3[1] / 10;
	p3[1] %= 10;
	p3[3] += p3[2] / 10;
	p3[2] %= 10;
	p3[4] += p3[3] / 10;
	p3[3] %= 10;

	for (int i = 0; i < 5; i++) {
	  if (i == 4 && p3[i] == 0) continue;
		if (!has[p3[i]]) 
			return 0;    
	}

	if (p1[3] != 0 || p2[3] != 0 || p3[4] != 0) return 0;
	return 1;
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		has[num[i]] = 1;
	}                              
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					for (int m = 0; m < n; m++) {
						int a, b, c, d, e;
						a = num[i];
						b = num[j];
						c = num[k];
						d = num[l];
						e = num[m];
						if (mult(a, b, c, d, e)) {
//							cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
							cnt++;
						}
					}
				}
			}
		}
	}
	cout << cnt << '\n';
}

int main() {
	setIO("crypt1");

	solve();

	return 0;
}   

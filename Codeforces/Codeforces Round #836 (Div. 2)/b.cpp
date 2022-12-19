#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

int n;
int u[1005];
/*
void rec(int pos, int ksor) {
	if (pos == n + 1) {
		int sum = 0;
		for (int i = 1; i <= 1000; i++) {
			if (u[i]) sum += i;
		}
		if (ksor == sum / n && sum % n == 0) {
			for (int i = 1; i <= 1000; i++) {
				if (u[i]) cout << i << ' ';
			}
			return;
		}
	}
	for (int i = 1; i <= 1000; i++) {
		u[i]++;
		rec(i + 1, ksor ^ i);
		u[i]--;
	}
}
*/
void solve() {
	cin >> n;
	if (n & 1) {
		for (int i = 0; i < n; i++) cout << n << ' ';
		cout << '\n';
		return;
	}
	cout << 1 << ' ';
	for (int i = 2; i < n; i++) cout << 2 << ' ';
	cout << 3 << '\n';
/*   
	for (int a = 1; a <= 5; a++) {
		for (int b = a; b <= 5; b++) {
			for (int c = b; c <= 5; c++) {
				for (int d = c; d <= 5; d++) {
				for (int e = d; e <= 5; e++) {
				for (int f = e; f <= 5; f++) {
					 int ksor = (a ^ b ^ c ^ d ^ e ^ f);
					 int sum = a + b + c + d + e + f;
					 if (ksor == sum / n && sum % n == 0) {
					 	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
					 }}}
				}
			}
		}
	}
*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 

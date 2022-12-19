#include<bits/stdc++.h>

using namespace std;

void solve() {
	for (int i = 0; i <= 10; i++) {
		cout << i << ' ' << ~i << '\n';
	}
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
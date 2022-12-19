/***
    AUTHOR:    shabylkhan
    CREATED:   13.08.2022 16:36:56

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	bool cards[2 * n + 1] = {false};
	vector<int> round(n);

	for (int i = 0; i < n; i++) {
		cin >> round[i];
		cards[round[i]] = true;
	}
	int points = 0;
	for (int i = 0; i < n; i++) {
		if (i < n / 2) {
			for (int card = 2 * n; card > 0; card--) {       
				if (card > round[i] && !cards[card]) {
					cards[card] = 1;
					points++;
					break;
				}
			}
		}
		else {
			for (int card = 1; card <= 2 * n; card++) {
				if (card < round[i] && !cards[card]) {
					cards[card] = 1;
					points++;
					break;
				}
			}
		}
	}
	cout << points << '\n';
}

int main() {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
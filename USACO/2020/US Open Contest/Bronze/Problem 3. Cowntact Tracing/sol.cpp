/***
    AUTHOR:    shabylkhan
    CREATED:   08.07.2022 15:14:02

***/

#include<bits/stdc++.h>

using namespace std;

bool cow_ends_infected[101];
int N, cowx[251], cowy[251];

bool consistent_with_data(int patient_zero, int K) {
	bool infected[101] = {false};
	int num_handshakes[101] = {0};
	infected[patient_zero] = 1;
	for (int t = 0; t <= 250; t++) {
		int x = cowx[t], y = cowy[t];
		if (x > 0) {
			if (infected[x]) num_handshakes[x]++;
			if (infected[y]) num_handshakes[y]++;
			if (num_handshakes[x] <= K && infected[x]) infected[y] = 1;
			if (num_handshakes[y] <= K && infected[y]) infected[x] = 1;
		}
	}
	for (int i = 1; i <= N; i++)
		if (infected[i] != cow_ends_infected[i]) return false;
	return true;
}

void solve() {
	int T, t, x, y;
	string s;

	cin >> N >> T >> s;
	for (int i = 1; i <= N; i++) 
		cow_ends_infected[i] = (s[i - 1] == '1');
	for (int i = 0; i < T; i++) {
		cin >> t >> x >> y;
		cowx[t] = x;
		cowy[t] = y;
	}
    
	bool possible_i[101] = {false};
	bool possible_K[252] = {false};
	for (int i = 1; i <= N; i++) {
		for (int K = 0; K <= 251; K++) {
			if (consistent_with_data(i, K)) {
				possible_i[i] = true, possible_K[K] = true;
			}
		}
	}

	int lower_K = 251, upper_K = 0, num_patient_zero = 0;
	for (int K = 0; K <= 251; K++) if (possible_K[K]) upper_K = K;
	for (int K = 251; K >= 0; K--) if (possible_K[K]) lower_K = K;
	for (int i = 1; i <= N; i++) if (possible_i[i]) num_patient_zero++;
	
	cout << num_patient_zero << ' ' << lower_K << ' ';
	if (upper_K == 251) cout << "Infinity\n";
	else cout << upper_K << '\n';
}

int main() {
	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 
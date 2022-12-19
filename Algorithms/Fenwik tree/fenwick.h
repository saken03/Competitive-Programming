#pragma once

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) {
		while (pos < sz(s)) {
			s[pos] += dif;
			pos += pos & -pos;
		}
	}
}

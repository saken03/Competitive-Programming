int lsb(int pos) {
	return pos & -pos;
}

void update(int pos, int val) {
	while (pos <= n) {
		fenw[pos] += val;
		pos += lsb(pos);
	}
}

int query(int pos) {
	int sum = 0;
	while (pos > 0) {
		sum += fenw[pos];
		pos -= lsb(pos);
	}
	return sum;
}
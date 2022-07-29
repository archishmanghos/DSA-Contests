int steps(int n) {
	int ans = 0;
	while (n > 0) {
		ans += 1;
		n >>= 1;
	}

	return ans;
}
int reduceArray( vector<int> & v) {
	int ans = 0;
	for (int i : v) ans += steps(i);
	return ans;
}

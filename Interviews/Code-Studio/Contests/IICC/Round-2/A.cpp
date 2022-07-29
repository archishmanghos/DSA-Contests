string change(int X) {
	if (X == 0) return "0";
	string ans = "";
	bool one = false;
	for (int i = 31; i >= 0; i--) {
		if ((X >> i) & 1) {
			ans += '1';
			one = true;
		}
		else {
			if (one) ans += '0';
		}
	}

	return ans;
}
int stringConversion(string s, vector<int>&arr) {
	string t = "";
	for (int i : arr) {
		t += change(i);
	}

	return s == t;
}

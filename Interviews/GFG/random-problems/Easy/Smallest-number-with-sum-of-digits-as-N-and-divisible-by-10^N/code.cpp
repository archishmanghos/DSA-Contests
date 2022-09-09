string digitsNum(int N) {
	string ans = "";
	if (N % 9) ans += (N % 9) + '0';
	for (int i = 1; i <= (N / 9); i++) ans += '9';
	for (int i = 1; i <= N; i++) ans += '0';
	return ans;
}
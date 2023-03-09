#include <bits/stdc++.h>
#define int long long

int cache[14][2][2][110][110];
int dp(int idx, int start, int exceed, int sod, int rem, std::string &s) {
	if (idx == s.size()) return (sod == 0 and rem == 1);
	int &answer = cache[idx][start][exceed][sod][rem], end = (exceed ? 9 : (s[idx] - '0'));
	if (answer != -1) return answer;

	answer = 0;
	for (int i = 0; i <= end; i++) {
		if (i <= sod) {
			answer += dp(idx + 1, (start | (i > 0)), (exceed | (i < (s[idx] - '0'))), sod - i, (start or (i > 0) ? (rem / std::__gcd(rem, i)) : rem), s);
		}
	}

	return answer;
}

std::string integerTostring (int x) {
	if (x == 0) return "0";
	std::string answer = "";
	while (x) {
		answer += (x % 10) + '0';
		x /= 10;
	}

	reverse(answer.begin(), answer.end());
	return answer;
}

void solve() {
	int A, B; std::cin >> A >> B;
	std::string _A = integerTostring(A - 1);
	std::string _B = integerTostring(B);

	int n1 = _A.size(), n2 = _B.size();
	int answer = 0;
	for (int i = 1; i <= n2 * 9; i++) {
		memset(cache, -1, sizeof(cache));
		int ans = dp(0, 0, 0, i, i, _B);
		answer += ans;
	}
	for (int i = 1; i <= n1 * 9; i++) {
		memset(cache, -1, sizeof(cache));
		int ans = dp(0, 0, 0, i, i, _A);
		answer -= ans;
	}

	std::cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	for (int i = 1; i <= T; i++) {
		std::cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
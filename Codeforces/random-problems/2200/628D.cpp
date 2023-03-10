#include <bits/stdc++.h>
#define int long long

std::string findDiff(std::string str1, std::string str2) {
	std::string str = "";
	int n1 = str1.length(), n2 = str2.length();
	std::reverse(str1.begin(), str1.end());
	std::reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n2; i++) {
		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else carry = 0;
		str.push_back(sub + '0');
	}

	for (int i = n2; i < n1; i++) {
		int sub = ((str1[i] - '0') - carry);
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else carry = 0;
		str.push_back(sub + '0');
	}

	std::reverse(str.begin(), str.end());
	return str;
}

std::string integerToString (int x) {
	if (x == 0) return "0";
	std::string answer = "";
	while (x) {
		answer += (x % 10) + '0';
		x /= 10;
	}

	std::reverse(answer.begin(), answer.end());
	return answer;
}

const int MOD = 1e9 + 7;

int dp(int idx, int start, int exceed, int rem, int M, int D, std::string &S, std::vector<std::vector<std::vector<std::vector<int>>>> &cache) {
	if (idx == S.size()) return rem == 0;
	int &answer = cache[idx][start][exceed][rem], end = (exceed ? 9 : (S[idx] - '0'));
	if (answer != -1) return answer;

	answer = 0;
	if (start == 1) {
		if (D <= end) answer = (answer + dp(idx + 1, start + 1, (exceed | (D < end)), (rem * 10 + D) % M, M, D, S, cache) % MOD) % MOD;
	} else {
		for (int i = 0; i <= end; i++) {
			if (i == D) continue;
			int preStart = start;
			if (!start) start += i > 0;
			else start -= 1;
			answer = (answer + dp(idx + 1, start, (exceed | (i < end)), (rem * 10 + i) % M, M, D, S, cache) % MOD) % MOD;
			start = preStart;
		}
	}

	return answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int M, D; std::cin >> M >> D;
	std::string A, B; std::cin >> A >> B;

	std::string _M = integerToString(M);
	if (_M.size() >= B.size() and _M > B) {
		std::cout << 0 << '\n';
		return 0;
	}

	int n2 = B.size(), n1 = A.size();
	std::vector<std::vector<std::vector<std::vector<int>>>> cache(n2, std::vector<std::vector<std::vector<int>>> (3, std::vector<std::vector<int>> (2, std::vector<int>(M))));

	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				cache[i][j][k].assign(M, -1);
			}
		}
	}
	int answer1 = dp(0, 0, 0, 0, M, D, B, cache);
	if (A != "0") {
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 2; k++) {
					cache[i][j][k].assign(M, -1);
				}
			}
		}
		A = findDiff(A, "1");
		int answer2 = dp(0, 0, 0, 0, M, D, A, cache);
		std::cout << (answer1 - answer2 + MOD) % MOD << '\n';
		return 0;
	}

	std::cout << answer1 << '\n';
	return 0;
}
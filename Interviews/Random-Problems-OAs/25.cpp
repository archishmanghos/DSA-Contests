#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

string integerToString (int x) {
	if (x == 0) return "0";
	string answer = "";
	while (x > 0) {
		answer += (x % 10) + '0';
		x /= 10;
	}

	reverse(answer.begin(), answer.end());
	return answer;
}

int stringToInteger (string s) {
	int answer = 0, j = 1;
	while (s.size() > 0) {
		answer += j * (s.back() - '0');
		j *= 10;
		s.pop_back();
	}

	return answer;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; cin >> N >> K;
	string N1 = integerToString(N);
	int n = N1.size(), answer = 1e9 + 7;

	for (int i = 0; i < (1 << n); i++) {
		string newNum = "";
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				newNum += N1[j];
			}
		}

		int newN = stringToInteger(newNum);
		if (newN <= K) continue;

		answer = min(answer, newN);
	}

	cout << answer;
	return 0;
}
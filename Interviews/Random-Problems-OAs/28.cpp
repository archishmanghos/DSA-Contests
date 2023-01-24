#include <bits/stdc++.h>
using namespace std;

string integerToString (int x) {
	if (x == 0) return "0";
	string answer = "";
	while (x) {
		answer += (x % 10) + '0';
		x /= 10;
	}

	reverse(answer.begin(), answer.end());
	return answer;
}

void Occurance(char *st) {
	size_t len = strlen(st);
	int64_t count = 1;
	string answer = "";
	for (int i = 1; i < len; i++) {
		if (st[i] == st[i - 1]) count += 1;
		else {
			answer += st[i - 1] + integerToString(count);
			count = 1;
		}
	}

	answer += st[len - 1] + integerToString(count);
	cout << answer;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char st[1000];
	cin >> st;
	Occurance(st);

	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

string findDiff(string str1, string str2) {
	string str = "";
	int n1 = str1.length(), n2 = str2.length();
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

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

	reverse(str.begin(), str.end());
	return str;
}

void solve() {
	string S; cin >> S;
	int K; cin >> K;

	if (K == 0) {
		cout << S << '\n';
		return;
	}

	while (S.size() < 4) S.push_back('0');
	string pre = "";
	string X1 = S, X2 = S;
	sort(X1.begin(), X1.end());
	reverse(X1.begin(), X1.end());
	sort(X2.begin(), X2.end());
	string answer = "";

	while (X1 != pre and K--) {
		pre = X1;
		string X = findDiff(X1, X2);
		X1 = X2 = X;
		answer = X;
		sort(X1.begin(), X1.end());
		reverse(X1.begin(), X1.end());
		sort(X2.begin(), X2.end());
	}

	reverse(answer.begin(), answer.end());
	while (answer.size() > 1 and answer.back() == '0') answer.pop_back();
	reverse(answer.begin(), answer.end());
	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
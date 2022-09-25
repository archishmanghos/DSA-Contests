#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int dp(int preK, int N, int A, int B) {
	if (N == 0) {
		return 1;
	}

	int possible[4] = {preK + 1, preK + 2, preK - 2, preK - 1}, ans = 0;
	for (int i = 0; i < 4; i++) {
		if (possible[i] >= A and possible[i] <= B) {
			ans += dp(possible[i], N - 1, A, B);
		}
	}

	return ans;
}

int process(int input1, int input2, int input3, int input4) {
	vector<vector<int>> cache(input4 + 2, vector<int>(input1 + 2, -1));
	return dp(input2, input1 - 1, input3, input4);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, A, B; cin >> N >> K >> A >> B;
	cout << process(N, K, A, B);

	return 0;
}
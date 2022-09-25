#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int collectMaxApples(int input1, vector<int> &input2) {
	int ans = 0, minn = 1e9;
	for (int i = input1 - 1; i >= 0; i--) {
		minn = min(minn, input2[i]);
		ans = max(ans, minn * (input1 - i));
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << collectMaxApples(N, A);
	return 0;
}
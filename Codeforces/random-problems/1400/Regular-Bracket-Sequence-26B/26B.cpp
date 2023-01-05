#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

using namespace std;

string S;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;
	int N = S.size(), count = 0, answer = N;
	for (int i = 0; i < N; i++) {
		count += S[i] == '(' ? 1 : -1;
		if (count < 0) answer -= 1;
		count = max(0, count);
	}

	cout << answer - abs(count);

	return 0;
}
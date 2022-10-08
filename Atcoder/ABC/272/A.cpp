#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, ans = 0, A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		ans += A;
	}

	cout << ans;
	return 0;
}
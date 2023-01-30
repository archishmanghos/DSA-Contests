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

	int N; cin >> N;
	int cnt[2] = {0};
	for (int i = 1; i <= N; i++) {
		string S; cin >> S;
		cnt[0] += S == "Against";
		cnt[1] += S == "For";
	}

	cout << (cnt[1] > cnt[0] ? "Yes" : "No");
	return 0;
}
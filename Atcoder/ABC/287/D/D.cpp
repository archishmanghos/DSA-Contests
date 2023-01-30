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

	string S, T; cin >> S >> T;
	int N1 = S.size(), N2 = T.size();
	vector<bool> pref(N2 + 2, false), suff(N2 + 2, false);

	pref[0] = suff[0] = true;
	for (int i = 0; i < N2; i++) {
		if (S[i] == '?' or T[i] == '?' or S[i] == T[i]) pref[i + 1] = true;
		else break;
	}

	for (int i = N1 - 1, j = N2 - 1; j >= 0; i--, j--) {
		if (S[i] == '?' or T[j] == '?' or S[i] == T[j]) suff[N2 - j] = true;
		else break;
	}

	for (int i = 0; i <= N2; i++) {
		if (pref[i] and suff[N2 - i]) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}
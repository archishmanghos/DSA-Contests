#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int BinExp(int a, int n, int mod = 1e9 + 7)	{
	int ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans = ((ans % mod) * (a % mod)) % mod;
			--n;
		}
		else {
			a = ((a % mod) * (a % mod)) % mod;
			n /= 2;
		}
	}
	return ans;
}

// https://github.com/archishmanghos/DSA-Functions/blob/master/Maths/Binary%20Modulo%20Exponentiation.cpp

void solve() {

	int A, N; cin >> A >> N;
	int median = N / 2;
	if (A > 0) cout << BinExp(A, median) << '\n';
	else cout << 1 << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int add(int a, int b, int mod = 1e9 + 7) {
	return ((a % mod) + (b % mod)) % mod;
}

int sub(int a, int b, int mod = 1e9 + 7) {
	return ((a % mod) - (b % mod) + mod) % mod;
}

int mul(int a, int b, int mod = 1e9 + 7) {
	return ((a % mod) * (b % mod)) % mod;
}

void solve() {
	int N, X, Y, A, B; cin >> N;
	int sumXSquares = 0, sumYSquares = 0, sumX = 0, sumY = 0, sumASquares = 0, sumBSquares = 0, sumA = 0, sumB = 0;

	for (int i = 1; i <= N; i++) {
		cin >> X >> Y;
		sumXSquares += (X * X);
		sumYSquares += (Y * Y);
		sumX += X;
		sumY += Y;
	}

	int M; cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A >> B;
		sumASquares += (A * A);
		sumBSquares += (B * B);
		sumA += A;
		sumB += B;
	}

	int leftSide = add(mul(M, add(sumXSquares, sumYSquares)), mul(N, add(sumASquares, sumBSquares))), rightSide = mul(2, add(mul(sumA, sumX), mul(sumB, sumY)));

	cout << sub(leftSide, rightSide) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
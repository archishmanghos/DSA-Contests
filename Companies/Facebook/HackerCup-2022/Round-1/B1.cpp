/*

Logic for both B1 and B2:

  (x1 - a1) ^ 2 + (y1 - b1) ^ 2 + (x2 - a1) ^ 2 + (y2 - b1) ^ 2
+ (x3 - a1) ^ 2 + (y3 - b1) ^ 2 + (x4 - a1) ^ 2 + (y4 - b1) ^ 2
+ (x1 - a2) ^ 2 + (y1 - b2) ^ 2 + (x2 - a2) ^ 2 + (y2 - b2) ^ 2
+ (x3 - a2) ^ 2 + (y3 - b2) ^ 2 + (x4 - a2) ^ 2 + (y4 - b2) ^ 2
+ (x1 - a3) ^ 2 + (y1 - b3) ^ 2 + (x2 - a3) ^ 2 + (y2 - b3) ^ 2
+ (x3 - a3) ^ 2 + (y3 - b3) ^ 2 + (x4 - a3) ^ 2 + (y4 - b3) ^ 2

= x1^2 + a1^2 + y1^2 + b1^2 + x2^2 + a1^2 + y2^2 + b1^2
+ x3^2 + a1^2 + y3^2 + b1^2 + x4^2 + a1^2 + y4^2 + b1^2
+ x1^2 + a2^2 + y1^2 + b2^2 + x2^2 + a2^2 + y2^2 + b2^2
+ x3^2 + a2^2 + y3^2 + b2^2 + x4^2 + a2^2 + y4^2 + b2^2
+ x1^2 + a3^2 + y1^2 + b3^2 + x2^2 + a3^2 + y2^2 + b3^2
+ x3^2 + a3^2 + y3^2 + b3^2 + x4^2 + a3^2 + y4^2 + b3^2

- 2x1a1 - 2b1y1 - 2x2a1 - 2y2b1 - 2x3a1 - 2y3b1 - 2x4a1 - 2y4b1
- 2x1a2 - 2b2y1 - 2x2a2 - 2y2b2 - 2x3a2 - 2y3b2 - 2x4a2 - 2y4b2
- 2x1a3 - 2b1y3 - 2x2a3 - 2y2b3 - 2x3a3 - 2y3b3 - 2x4a3 - 2y4b3

= 3(x1^2 + x2^2 + x3^2 + x4^2) + 4(a1^2 + a2^2 + a3^2 + b1^2 + b2^2 + b3^2)
- 2(x1 + x2 + x3 + x4)(a1 + a2 + a3) - 2(y1 + y2 + y3 + y4)(b1 + b2 + b3)

= M * (x1^2 + x2^2 + ... + xN^2) + N * (a1^2 + a2^2 + ... + aM^2)
- 2 ((x1 + x2 + ... + xN)(a1 + a2 + ... + aM) + (y1 + y2 + ... + yN)(b1 + b2 + ... + bM))

*/

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
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxn = 1e5 + 5;
int N, M, X, A[12], B[mxn], trap[mxn];
int cache[mxn];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> B[i];
	cin >> X;
	memset(trap, 0, sizeof(trap));
	for (int i = 1; i <= M; i++) trap[B[i]] = 1;
	memset(cache, 0, sizeof(cache));
	cache[0] = 1;

	for (int i = 1; i <= X; i++) {
		for (int j = 1; j <= N; j++) {
			if (i - A[j] >= 0 and !trap[i - A[j]]) {
				cache[i] = cache[i] | cache[i - A[j]];
			}
		}
	}

	cout << (cache[X] ? "Yes" : "No");
	return 0;
}
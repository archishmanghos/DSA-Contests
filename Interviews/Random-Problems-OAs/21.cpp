#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int M, A[1005];

void fundsContributed() {
	int totalFunds = 0;
	for (int i = 0; i < M; i++) totalFunds += A[i];
	for (int i = 0; i < M; i++) cout << totalFunds - A[i] << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;
	for (int i = 0; i < M; i++) cin >> A[i];
	fundsContributed();
	return 0;
}
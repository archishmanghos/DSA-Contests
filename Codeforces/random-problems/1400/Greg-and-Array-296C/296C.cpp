#include <bits/stdc++.h>
using namespace std;

const int mxN = 500500;
int N, M, K, A[mxN], X, Y;
vector<vector<int>> OP;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	OP.resize(M + 2);
	for (int i = 1; i <= M; i++) {
		OP[i].resize(4);
		for (int j = 1; j <= 3; j++) cin >> OP[i][j];
	}

	int countOperations[M + 2], addToOriginalArray[N + 2];
	memset(countOperations, 0, sizeof(countOperations));
	memset(addToOriginalArray, 0, sizeof(addToOriginalArray));

	for (int i = 1; i <= K; i++) {
		cin >> X >> Y;
		countOperations[X] += 1;
		countOperations[Y + 1] -= 1;
	}

	for (int i = 2; i <= M; i++) countOperations[i] += countOperations[i - 1];

	for (int i = 1; i <= M; i++) {
		addToOriginalArray[OP[i][1]] += countOperations[i] * OP[i][3];
		addToOriginalArray[OP[i][2] + 1] -= countOperations[i] * OP[i][3];
	}

	for (int i = 2; i <= N; i++) addToOriginalArray[i] += addToOriginalArray[i - 1];

	for (int i = 1; i <= N; i++) cout << A[i] + addToOriginalArray[i] << ' ';
	return 0;
}
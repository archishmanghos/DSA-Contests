#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int T, N, M, K, A[mxN], B[mxN];

void solve() {
    
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
    for(int i = 1; i <= M; i++) cin >> B[i];
    cin >> K;
	
	vector<int> prefSumA(N + 2, 0), suffSumA(N + 2, 0), prefSumB(M + 2, 0), suffSumB(M + 2, 0);
	prefSumA[1] = A[1], prefSumB[1] = B[1], suffSumA[N] = A[N], suffSumB[M] = B[M];
	for(int i = 2; i <= N; i++) prefSumA[i] += prefSumA[i - 1] + A[i];
	for(int i = 2; i <= M; i++) prefSumB[i] += prefSumB[i - 1] + B[i];
	for(int i = N - 1; i >= 1; i--) suffSumA[i] += suffSumA[i + 1] + A[i];
	for(int i = M - 1; i >= 1; i--) suffSumB[i] += suffSumB[i + 1] + B[i];

	int ans = 0;
	for(int i = 0; i <= K; i++){
		int quesFromA = i, quesFromB = K - i;
		if(quesFromA <= N and quesFromB <= M){
			int pointsA = 0;
			for(int j = 0; j <= quesFromA; j++){
				int quesFromAFront = j, quesFromABack = quesFromA - j, points = 0;
				points += (quesFromAFront > 0 ? prefSumA[quesFromAFront] : 0);
				points += (quesFromABack > 0 ? suffSumA[N - quesFromABack + 1] : 0);
				pointsA = max(pointsA, points);
			}
			int pointsB = 0;
			for(int j = 0; j <= quesFromB; j++){
				int quesFromBFront = j, quesFromBBack = quesFromB - j, points = 0;
				points += (quesFromBFront > 0 ? prefSumB[quesFromBFront] : 0);
				points += (quesFromBBack > 0 ? suffSumB[M - quesFromBBack + 1] : 0);
				pointsB = max(pointsB, points);
			}
			ans = max(ans, pointsA + pointsB);
		}
	}

	cout << ans << '\n';

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
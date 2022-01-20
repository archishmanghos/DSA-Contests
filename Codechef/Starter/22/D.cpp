#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, cache[1005][1005];

int dp(int indexA, int indexB, int &N, string &A, string &B, vector<int> &prefixSumOnesA, vector<int> &prefixSumOnesB){
	if(indexA == N and indexB == N){
		return 0;
	}

	int &ans = cache[indexA][indexB];
	if(ans != -1){
		return ans;
	}

	ans = INF;
	int onesTillNow, zerosTillNow, zerosLeft, inversion;

	if(indexA < N and indexB < N){
		onesTillNow = prefixSumOnesA[indexA] + (indexB > 0 ? prefixSumOnesB[indexB - 1] : 0);
		zerosTillNow = indexA + 1 + indexB - onesTillNow;
		inversion = (N - prefixSumOnesA[N - 1]) + (N - prefixSumOnesB[N - 1]) - zerosTillNow; // zeroes left

		if(A[indexA] == '1'){
			ans = dp(indexA + 1, indexB, N, A, B, prefixSumOnesA, prefixSumOnesB) + inversion;
		}
		else{
			ans = dp(indexA + 1, indexB, N, A, B, prefixSumOnesA, prefixSumOnesB);
		}

		onesTillNow = prefixSumOnesB[indexB] + (indexA > 0 ? prefixSumOnesA[indexA - 1] : 0);
		zerosTillNow = indexA + indexB + 1 - onesTillNow;
		inversion = (N - prefixSumOnesA[N - 1]) + (N - prefixSumOnesB[N - 1]) - zerosTillNow; // zeroes left;

		if(B[indexB] == '1'){
			ans = min(ans, dp(indexA, indexB + 1, N, A, B, prefixSumOnesA, prefixSumOnesB) + inversion);
		}
		else{
			ans = min(ans, dp(indexA, indexB + 1, N, A, B, prefixSumOnesA, prefixSumOnesB));
		}
	}
	else if(indexA == N){
		onesTillNow = prefixSumOnesB[indexB] + (indexA > 0 ? prefixSumOnesA[indexA - 1] : 0);
		zerosTillNow = indexA + indexB + 1 - onesTillNow;
		inversion = (N - prefixSumOnesA[N - 1]) + (N - prefixSumOnesB[N - 1]) - zerosTillNow; // zeroes left;

		if(B[indexB] == '1'){
			ans = min(ans, dp(indexA, indexB + 1, N, A, B, prefixSumOnesA, prefixSumOnesB) + inversion);
		}
		else{
			ans = min(ans, dp(indexA, indexB + 1, N, A, B, prefixSumOnesA, prefixSumOnesB));
		}
	}
	else if(indexB == N){
		onesTillNow = prefixSumOnesA[indexA] + (indexB > 0 ? prefixSumOnesB[indexB - 1] : 0);
		zerosTillNow = indexA + 1 + indexB - onesTillNow;
		inversion = (N - prefixSumOnesA[N - 1]) + (N - prefixSumOnesB[N - 1]) - zerosTillNow; // zeroes left

		if(A[indexA] == '1'){
			ans = dp(indexA + 1, indexB, N, A, B, prefixSumOnesA, prefixSumOnesB) + inversion;
		}
		else{
			ans = dp(indexA + 1, indexB, N, A, B, prefixSumOnesA, prefixSumOnesB);
		}
	}

	return ans;
}

void solve()
{
    int N;
    string A, B;
    cin >> N >> A >> B;

    vector<int> prefixSumOnesA(N + 2), prefixSumOnesB(N + 2);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < N; i++) {
    	cnt1 += A[i] == '1';
    	cnt2 += B[i] == '1';
    	prefixSumOnesA[i] = cnt1;
    	prefixSumOnesB[i] = cnt2;
    }

    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0, N, A, B, prefixSumOnesA, prefixSumOnesB) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}
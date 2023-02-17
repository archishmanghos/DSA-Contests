#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long solve(int N, int K, vector<long long> GeekNum) {
		if (N <= K) return GeekNum[N - 1];
		long long sum = 0;
		for (int i : GeekNum) sum += i;
		for (int i = K ; i < N; i++) {
			GeekNum.push_back(sum);
			sum += GeekNum[i];
			sum -= GeekNum[i - K];
		}

		return GeekNum.back();
	}
};
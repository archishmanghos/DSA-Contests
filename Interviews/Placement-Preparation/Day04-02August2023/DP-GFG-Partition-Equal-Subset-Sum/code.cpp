#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int equalPartition(int N, int arr[]) {
		int totalSum = accumulate (arr, arr + N, 0);
		if (totalSum & 1) return 0;
		totalSum >>= 1;

		int cache[N + 2][totalSum + 2];
		memset(cache, 0, sizeof(cache));
		for (int i = 0; i <= totalSum; i++) {
			if (i == arr[0]) cache[0][i] = 1;
		}
		for (int i = 0; i < N; i++) cache[i][0] = 1;
		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= totalSum; j++) {
				cache[i][j] = cache[i - 1][j];
				if (j >= arr[i]) cache[i][j] |= cache[i - 1][j - arr[i]];
			}
		}

		return cache[N - 1][totalSum];
	}
};
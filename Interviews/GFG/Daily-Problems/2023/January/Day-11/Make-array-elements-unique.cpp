#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long int minIncrements(vector<int> arr, int N) {
		sort (arr.begin(), arr.end());
		int64_t answer = 0;
		for (int i = 1; i < N; i++) {
			if (arr[i] <= arr[i - 1]) {
				answer += arr[i - 1] + 1 - arr[i];
				arr[i] = arr[i - 1] + 1;
			}
		}
		return answer;
	}
};
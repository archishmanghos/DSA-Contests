#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int solve(int N, int K, vector<int> &arr) {
		vector<int> factors;
		int totSum = accumulate (arr.begin(), arr.end(), 0);
		factors.push_back(totSum);
		for (int i = 2; i * i <= totSum; i++) {
			if (totSum % i == 0) {
				factors.push_back(i);
				if ((totSum / i) != i) factors.push_back(totSum / i);
			}
		}

		int answer = 1;
		for (int fact : factors) {
			int partition = 0, sum = 0;
			for (int i = 0; i < arr.size(); i++) {
				sum += arr[i];
				partition += sum % fact == 0;
			}

			if (partition >= K) answer = max (answer, fact);
		}

		return answer;
	}
};
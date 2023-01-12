#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimizeSum(int N, vector<int> arr) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < N; i++) pq.push(arr[i]);

		int answer = 0;
		while (pq.size() > 1) {
			int sum = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();

			pq.push(sum);
			answer += sum;
		}

		return answer;
	}
};
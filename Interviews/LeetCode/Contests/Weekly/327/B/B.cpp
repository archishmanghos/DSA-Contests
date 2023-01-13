#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long maxKelements(vector<int>& nums, int k) {
		priority_queue<int> pq;
		for (int i : nums) pq.push(i);

		int64_t answer = 0;
		while (k--) {
			int last = pq.top();
			pq.pop();
			answer += last;
			last = (last + 2) / 3;
			pq.push(last);
		}

		return answer;
	}
};
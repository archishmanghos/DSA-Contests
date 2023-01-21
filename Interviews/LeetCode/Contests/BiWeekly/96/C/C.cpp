#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<vector<int>> v;
		for (int i = 0; i < nums1.size(); i++) {
			v.push_back({nums1[i], nums2[i]});
		}

		sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b) {
			if (a[1] != b[1]) return a[1] > b[1];
			return a[0] > b[0];
		});

		priority_queue<int, vector<int>, greater<int>> pq;
		int64_t sum = 0;
		for (int i = 0; i < k; i++) {
			pq.push(v[i][0]);
			sum += v[i][0];
		}

		int64_t answer = sum * v[k - 1][1];
		for (int i = k; i < nums1.size(); i++) {
			sum += v[i][0];
			pq.push(v[i][0]);
			sum -= pq.top();
			pq.pop();
			answer = max(answer, sum * v[i][1]);
		}

		return answer;
	}
};
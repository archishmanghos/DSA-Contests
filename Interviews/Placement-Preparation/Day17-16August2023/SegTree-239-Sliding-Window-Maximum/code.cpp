#include <bits/stdc++.h>
using namespace std;

class SegTree {
private:
	int n;
	vector<int> arr;
	const int INF = 1e9 + 7;
public:
	SegTree(int n) {
		this->n = 1;
		while (this->n < n) this->n <<= 1;
		this->n <<= 1;

		this->arr.assign(this->n, -INF);
	}

	int buildAndAnswer(vector<int> &arr, int k) {
		for (int i = (n >> 1); i < n; i++) {
			if ((i - (n >> 1)) < k) this->arr[i] = arr[i - (n >> 1)];
			else break;
		}

		for (int i = (n >> 1) - 1; i >= 0; i--) {
			this->arr[i] = max(this->arr[i * 2], this->arr[i * 2 + 1]);
		}

		return this->arr[1];
	}

	int updateAndAnswer(int idx, int value) {
		int k = (n >> 1) + idx;
		arr[k] = value;
		while (k > 0) {
			k >>= 1;
			arr[k] = max(arr[k * 2], arr[k * 2 + 1]);
		}

		return arr[1];
	}
};

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		SegTree st(k);
		vector<int> answer;
		answer.push_back(st.buildAndAnswer(nums, k));
		for (int i = k; i < nums.size(); i++) answer.push_back(st.updateAndAnswer(i % k, nums[i]));
		return answer;
	}
};
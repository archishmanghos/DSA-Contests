class Solution {
public:
	int maximizeSum(int a[], int n) {
		vector<int> mark(100001, 0);
		for (int i = 0; i < n; i++) {
			mark[a[i]] += 1;
		}

		int ans = 0;
		for (int i = 100000; i >= 1; i--) {
			ans += mark[i] * i;
			mark[i - 1] = max(mark[i - 1] - mark[i], 0);
		}

		return ans;
	}
};
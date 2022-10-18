class Solution {
public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A) {
		vector<int> ans(N * N);
		for (int i = 0, j = 0, idx = 0; i < 2 * N; i++) {
			if (i == N) continue;
			int k = i < N ? 0 : i % N, l = j;
			while (k < N and l >= 0) {
				ans[idx++] = A[k++][l--];
			}
			j = j == N - 1 ? j : j + 1;
		}

		return ans;
	}
};
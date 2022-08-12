#include <bits/stdc++.h>
using namespace std;

int findMaxArea(vector<int> arr, int n) {
	vector<int> st;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int compTo = (i == n ? INT_MIN : arr[i]);
		while (st.size() and arr[st.back()] >= compTo) {
			int height = arr[st.back()];
			st.pop_back();
			int leftSmall = (st.size() ? st.back() : -1);
			int rightSmall = i;
			ans = max(ans, height * (rightSmall - leftSmall - 1));
		}
		st.push_back(i);
	}

	return ans;
}

int32_t main() {

	int n, m; cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int> (m));
	for (auto &all : matrix) {
		for (int &col : all) cin >> col;
	}

	vector<int> arr(m, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[j] += (matrix[i][j] == 0 ? -arr[j] : 1);
		}
		ans = max(ans, findMaxArea(arr, m));
	}

	cout << ans;
	return 0;
}
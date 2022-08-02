int getCount(int x, int n, int m, vector<vector<int>>& matrix) {
    int r = 0, c = m - 1, ans = 0;
    while (r<n and c >= 0) {
        if (matrix[r][c] <= x) ans += c + 1, r++;
        else c--;
    }

    return ans;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size(), low = matrix[0][0], high = matrix[n - 1][m - 1];
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (getCount(mid, n, m, matrix) >= k)high = mid - 1;
        else low = mid + 1;
    }

    return low;
}
class Solution {
   public:
    int dp(int index, int sum, int* arr, int totSum, vector<vector<int>>& cache) {
        if (index == 0) {
            int sum1 = sum + arr[index];
            int sum2 = totSum - sum;
            return min(abs(sum1 - (totSum - sum1)), abs(sum - sum2));
        }
        if (cache[index][sum] != -1) {
            return cache[index][sum];
        }

        int ans = min(dp(index - 1, sum, arr, totSum, cache), dp(index - 1, sum + arr[index], arr, totSum, cache));
        return cache[index][sum] = ans;
    }

    int minDifference(int arr[], int n) {
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        vector<vector<int>> cache(n, vector<int>(totSum + 1, -1));
        return dp(n - 1, 0, arr, totSum, cache);
    }
};
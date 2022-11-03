class Solution {
public:
    int removals(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int i = 0, j = 0, ans = 1;
        while (j < arr.size()) {
            if (arr[j] - arr[i] <= k) {
                ans = max(ans, j - i + 1);
                j += 1;
            } else {
                while (arr[j] - arr[i] > k) {
                    i += 1;
                }
            }
        }

        return (int)arr.size() - ans;
    }
};
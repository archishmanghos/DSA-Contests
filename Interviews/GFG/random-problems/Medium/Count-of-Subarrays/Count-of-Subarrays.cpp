class Solution {
   public:
    // #define ll long long
    ll countSubarray(int arr[], int n, int k) {
        ll ans = 0;
        vector<int> maxx = {0, -1};
        for (int i = 0; i < n; i++) {
            if (arr[i] > k) {
                maxx = {arr[i], i};
            }
            ans += maxx[1] + 1;
        }

        return ans;
    }
};
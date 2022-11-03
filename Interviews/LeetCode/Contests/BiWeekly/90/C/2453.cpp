class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i] % space, nums[i]};
        }

        sort(v.begin(), v.end());
        int ans = 0, cnt = 1, maxCnt = 0;
        for (int i = 1; i < n; i++) {
            if (v[i].first == v[i - 1].first) {
                cnt += 1;
            } else {
                if (cnt == maxCnt) {
                    ans = min(ans, v[i - cnt].second);
                } else if (cnt > maxCnt) {
                    maxCnt = cnt;
                    ans = v[i - cnt].second;
                }
                cnt = 1;
            }
        }

        if (cnt == maxCnt) {
            ans = min(ans, v[n - cnt].second);
        } else if (cnt > maxCnt) {
            ans = v[n - cnt].second;
        }
        return ans;
    }
};
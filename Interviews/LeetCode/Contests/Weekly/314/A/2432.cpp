class Solution {
   public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<int> ans = {0, -1};
        int startTime = 0;
        for (auto i : logs) {
            int id = i[0], endTime = i[1];
            int timeSpent = endTime - startTime;
            if (timeSpent > ans[0]) {
                ans = {timeSpent, id};
            } else if (timeSpent == ans[0]) {
                if (id < ans[1]) {
                    ans[1] = id;
                }
            }
            startTime = endTime;
        }

        return ans[1];
    }
};
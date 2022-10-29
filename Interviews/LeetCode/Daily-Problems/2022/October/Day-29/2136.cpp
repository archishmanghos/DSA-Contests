class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> indices(n);
        iota (indices.begin(), indices.end(), 0);

        sort (indices.begin(), indices.end(), [&](int a, int b) {
            return growTime[a] > growTime[b];
        });

        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += plantTime[indices[i]];
            ans = max(ans, sum + growTime[indices[i]]);
        }

        return ans;
    }
};
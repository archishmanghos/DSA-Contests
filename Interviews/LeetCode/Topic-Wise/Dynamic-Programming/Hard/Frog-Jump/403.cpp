class Solution {
public:
    int cache[2001][2001];
    int dp(int idx, int pre, int n, map<int, int> &stonepos, map<int, int> &posstone) {
        if (idx == n - 1) return 1;
        if (cache[idx][pre] != -1) return cache[idx][pre];

        int ans  = 0;
        if (idx == 0) {
            if (stonepos.find(1) != stonepos.end()) {
                ans |= dp(stonepos[1], 0, n, stonepos, posstone);
            }
        } else {
            int jump = posstone[idx] - posstone[pre];
            int pos1 = posstone[idx] + jump - 1;
            int pos2 = posstone[idx] + jump;
            int pos3 = posstone[idx] + jump + 1;

            if (stonepos.find(pos1) != stonepos.end() and stonepos[pos1] > idx) {
                ans |= dp(stonepos[pos1], idx, n, stonepos, posstone);
            }
            if (stonepos.find(pos2) != stonepos.end() and stonepos[pos2] > idx) {
                ans |= dp(stonepos[pos2], idx, n, stonepos, posstone);
            }
            if (stonepos.find(pos3) != stonepos.end() and stonepos[pos3] > idx) {
                ans |= dp(stonepos[pos3], idx, n, stonepos, posstone);
            }
        }

        return cache[idx][pre] = ans;
    }

    bool canCross(vector<int>& stones) {
        map<int, int> stonepos, posstone;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            stonepos[stones[i]] = i;
            posstone[i] = stones[i];
        }

        memset(cache, -1, sizeof(cache));
        return dp(0, 0, n, stonepos, posstone);
    }
};
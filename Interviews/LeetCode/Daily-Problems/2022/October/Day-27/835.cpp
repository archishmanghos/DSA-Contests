class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<int> pa, pb;
        for (int i = 0; i < n * n; i++) {
            if (img1[i / n][i % n] == 1) {
                pa.push_back((i / n) * 100 + (i % n));
            }
            if (img2[i / n][i % n] == 1) {
                pb.push_back((i / n) * 100 + (i % n));
            }
        }

        unordered_map<int, int> ump;
        for (int i : pa) {
            for (int j : pb) {
                ump[i - j] += 1;
            }
        }

        int ans = 0;
        for (auto i : ump) {
            ans = max(ans, i.second);
        }

        return ans;
    }
};
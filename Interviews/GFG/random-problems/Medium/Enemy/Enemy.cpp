class Solution {
public:
    int largestArea (int n, int m, int k, vector<vector<int>> &enemy) {
        if (k == 0) return n * m;
        
        vector<int> r, c;
        for (auto i: enemy) {
            r.push_back(i[0]);
            c.push_back(i[1]);
        }
        
        sort(r.begin(), r.end());
        sort(c.begin(), c.end());
        int maxr = max(n - r[k - 1], r[0] - 1), maxc = max(m - c[k - 1], c[0] - 1);
        for (int i = 1; i < k; i++) {
            maxr = max(maxr, r[i] - r[i - 1] - 1);
            maxc = max(maxc, c[i] - c[i - 1] - 1);
        }
        
        return maxr * maxc;
    }
};
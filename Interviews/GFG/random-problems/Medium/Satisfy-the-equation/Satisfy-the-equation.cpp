class Solution {
public:
    vector<int> satisfyEqn(int A[], int N) {
        unordered_map<int, vector<int>> ump;
        vector<int> ans = { -1, -1, -1, -1};
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int x = A[i] + A[j];
                if (ump.find(x) != ump.end()) {
                    if (ump[x][0] == i or ump[x][1] == i or ump[x][0] == j or ump[x][1] == j) continue;
                    vector<int> v = {ump[x][0], ump[x][1], i, j};
                    if (ans[0] == -1 or v < ans) {
                        ans = v;
                    }
                } else {
                    ump[x] = {i, j};
                }
            }
        }

        return ans;
    }
};
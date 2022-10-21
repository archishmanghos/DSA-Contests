class Solution {
public:
    bool endOfRoad(int x, int y, int R, int C, vector<vector<int>> &visited) {
        if (x < 0 or x >= R or y < 0 or y >= C) return true;
        if (visited[x][y]) return true;
        return false;
    }
    vector<int> reverseSpiral(int R, int C, vector<vector<int>> &a)  {
        vector<int> start = {0, 0}, ans(R * C);
        int i = 0, curDir = 0; // 0 for right, 1 for down, 2 for left and 3 for up
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        vector<vector<int>> visited(R, vector<int> (C, 0));

        while (1) {
            ans[i++] = a[start[0]][start[1]];
            visited[start[0]][start[1]] = 1;
            if (endOfRoad(start[0] + dx[curDir], start[1] + dy[curDir], R, C, visited)) {
                curDir = (curDir + 1) % 4;
            }

            start[0] += dx[curDir];
            start[1] += dy[curDir];

            if (endOfRoad(start[0], start[1], R, C, visited)) {
                break;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
bool valid(int rx, int cy, int n, int m) {
    return (rx >= 0 and rx < n and cy >= 0 and cy < m);
}
int found(int index, int rx, int cy, int n, int m, string &target, vector<vector<char> > &mat, vector<vector<bool>> &visited) {
    if (index == target.size() - 1) return target[index] == mat[rx][cy];
    if (target[index] != mat[rx][cy]) return 0;

    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, ans = 0;
    for (int i = 0; i < 4; i++) {
        if (valid(rx + dx[i], cy + dy[i], n, m) and !visited[rx + dx[i]][cy + dy[i]]) {
            visited[rx + dx[i]][cy + dy[i]] = true;
            ans += found(index + 1, rx + dx[i], cy + dy[i], n, m, target, mat, visited);
            visited[rx + dx[i]][cy + dy[i]] = false;
        }
    }

    return ans;
}
int findOccurrence(vector<vector<char> > &mat, string target) {
    int n = mat.size(), m = mat[0].size(), ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[i][j] = true;
            ans += found(0, i, j, n, m, target, mat, visited);
        }
    }

    return ans;
}
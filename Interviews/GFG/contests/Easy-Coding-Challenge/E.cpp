int maximum_problems(int n, vector<int>&problems) {
    int ans = 0, cnt = 1, prevProblem = problems[0];
    for (int i = 1; i < n; i++) {
        if (problems[i] > 2 * prevProblem) {
            ans = max(ans, cnt);
            cnt = 1;
        } else {
            cnt += 1;
        }
        prevProblem = problems[i];
    }

    ans = max(ans, cnt);
    return ans;
}
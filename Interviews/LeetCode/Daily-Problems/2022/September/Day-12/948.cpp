int bagOfTokensScore(vector<int>& tokens, int power) {
    int n = tokens.size(), curScore = 0, ans = 0, i = 0, j = n - 1;
    sort(tokens.begin(), tokens.end());
    while (i <= j) {
        if (power >= tokens[i]) {
            power -= tokens[i++];
            curScore += 1;
        } else if (curScore >= 1) {
            power += tokens[j--];
            curScore -= 1;
        } else {
            break;
        }
        ans = max(ans, curScore);
    }

    return ans;
}
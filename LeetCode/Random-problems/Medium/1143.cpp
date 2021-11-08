int cache[1005][1005];
int dp(string &text1, string &text2, int index1, int index2)
{
    if(index1 < 0 || index2 < 0)
        return 0;
    if(cache[index1][index2] != -1)
        return cache[index1][index2];
    int ans;
    if(text1[index1] == text2[index2])
        ans = dp(text1, text2, index1 - 1, index2 - 1) + 1;
    else
        ans = max(dp(text1, text2, index1 - 1, index2), dp(text1, text2, index1, index2 - 1));
    return cache[index1][index2] = ans;
}
int longestCommonSubsequence(string text1, string text2)
{
    int N1 = text1.size(), N2 = text2.size();
    memset(cache, -1, sizeof(cache));
    int ans = dp(text1, text2, N1 - 1, N2 - 1);
    return ans;
}

/*

Time Complexity: O(N*M)
Space Complexity: O(N*M)

Analysis: Classical LCS problem.

*/